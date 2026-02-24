#pragma once

#include "Core/World.hpp"
#include "Features/Domain/RangedPoisoning.hpp"
#include "Features/Events/UnitAbilityUsed.hpp"
#include "Features/Intents/AddEffectIntent.hpp"
#include "Features/Intents/RangedAttackIntent.hpp"

#include <random>

namespace sw::features::systems
{
	class Poisoning
	{
	public:
		static void onBeforeRangedAttack(core::World& world, intents::RangedAttackIntent& intent)
		{
			static std::random_device rd;
			static std::mt19937 gen(rd());
			static std::uniform_int_distribution<> dis(1, 1000);

			auto attackerId = intent.attackerId;
			auto targetId = intent.targetId;
			auto& poisoning = world.getComponent<domain::RangedPoisoning>();
			auto ability = poisoning.find(attackerId);
			if (ability == poisoning.end())
			{
				return;
			}

			if (dis(gen) > ability->second.chance)
			{
				return;
			}

			intent.cancel("ranged_poisoning");
			world.pushIntent(std::make_unique<intents::AddEffectIntent>(
					attackerId, targetId, intents::EffectType::Poison, 5, ability->second.poison));
			world.getEvents().event(world.getTick(), events::UnitAbilityUsed{attackerId, targetId, "poison"});
		}
	};
}
