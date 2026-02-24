#pragma once

#include <cstdint>

namespace sw::features::domain
{
	struct RangedPoisoning
	{
		uint32_t chance{};
		uint32_t poison{};
	};
}
