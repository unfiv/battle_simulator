#pragma once

#include "Core/Pipeline/Intent.hpp"

#include <cstdint>

namespace sw::features::intents
{
	enum class EffectType
	{
		Poison,
		Rending
	};

	struct AddEffectIntent : public core::pipeline::Intent
	{
		uint32_t sourceId;
		uint32_t targetId;
		EffectType effectType;
		uint32_t duration;
		uint32_t damage;

		AddEffectIntent(uint32_t source, uint32_t target, EffectType type, uint32_t ticks, uint32_t amount) :
				sourceId(source),
				targetId(target),
				effectType(type),
				duration(ticks),
				damage(amount)
		{}
	};
}
