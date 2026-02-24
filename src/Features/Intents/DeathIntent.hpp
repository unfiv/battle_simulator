#pragma once

#include "Core/Pipeline/Intent.hpp"

#include <cstdint>

namespace sw::features::intents
{
	struct DeathIntent : public core::pipeline::Intent
	{
		uint32_t unitId;

		explicit DeathIntent(uint32_t id) :
				unitId(id)
		{}
	};
}
