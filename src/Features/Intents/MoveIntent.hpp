#pragma once

#include "Core/Pipeline/Intent.hpp"

#include <cstdint>

namespace sw::features::intents
{
    struct MoveIntent : public core::pipeline::Intent
    {
        uint32_t unitId;

        core::Position posFrom;
        core::Position posTo;

        MoveIntent(uint32_t id, core::Position from, core::Position to)
            : unitId(id), posFrom(from), posTo(to) {}
    };
}