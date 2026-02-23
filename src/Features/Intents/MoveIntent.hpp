#pragma once

#include "Core/Pipeline/Intent.hpp"

#include <cstdint>

namespace sw::features::intents
{
    struct MoveIntent : public core::pipeline::Intent
    {
        uint32_t unitId;

        // TODO: migrate to Position struct
        uint32_t fromX, fromY;
        core::Position posTo;

        MoveIntent(uint32_t id, uint32_t fx, uint32_t fy, core::Position to)
            : unitId(id), fromX(fx), fromY(fy), posTo(to) {}
    };
}