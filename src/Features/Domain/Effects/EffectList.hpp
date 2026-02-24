#pragma once

#include "Features/Domain/Effects/ActiveEffect.hpp"

#include <vector>

namespace sw::features::domain::effects
{
	struct EffectList
	{
		std::vector<ActiveEffect> active;
	};
}
