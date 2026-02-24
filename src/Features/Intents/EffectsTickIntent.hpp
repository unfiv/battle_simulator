#pragma once

#include "Core/Pipeline/Intent.hpp"

#include <cstdint>

namespace sw::features::intents
{
	struct EffectsTickIntent : public core::pipeline::Intent
	{
		uint32_t unitId;

		explicit EffectsTickIntent(uint32_t id) :
				unitId(id)
		{}
	};
}
