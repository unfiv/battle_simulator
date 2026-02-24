#pragma once

#include "Core/World.hpp"
#include "Features/Domain/Effects/EffectData.hpp"

#include <any>

namespace sw::features::systems::effects
{
	class RendingEffect
	{
	public:
		static void apply(core::World& world, uint32_t targetId, domain::effects::ActiveEffect& effect)
		{
			// Just an effect, real damage is done during attack
		}
	};
}
