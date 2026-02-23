// Features/Systems/MovementSystem.hpp
#pragma once

#include "Core/World.hpp"
#include "Features/Intents/DamageIntent.hpp"

namespace sw::features::systems::DamageSystem {
    // Core logic for reducing HP
    static void apply(core::World& world, intents::DamageIntent& intent) {
        auto& health = world.getComponent<core::Health>(intent.targetId);
        health.current -= intent.amount;
    }
}