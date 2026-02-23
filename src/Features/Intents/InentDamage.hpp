#pragma once

#include "Core/Pipeline/Intent.hpp"

#include <cstdint>

namespace sw::features::intents
{
    struct DamageIntent : public core::pipeline::Intent
    {
        uint32_t attackerId;
        uint32_t targetId;
        int32_t damage;
        std::string type; // "melee", "ranged", "poison", "fire"

        DamageIntent(uint32_t att, uint32_t tar, int32_t dmg, std::string t)
            : attackerId(att), targetId(tar), damage(dmg), type(std::move(t)) {}
    };
}