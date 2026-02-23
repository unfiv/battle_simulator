#include "World.hpp"

#include <array>
#include <span>
#include <cassert>

#include "Core/Domain/Position.hpp"

#include "Features/Intents/DeathIntent.hpp"
#include "Features/Intents/EffectsTickIntent.hpp"

namespace sw::core
{
	void World::nextTick()
	{
		++tick;

		restrictions.clear();

		auto ids = creationOrder;

        const std::array<std::type_index, 2> maintenanceChain = {
            std::type_index(typeid(features::intents::EffectsTickIntent)),
            std::type_index(typeid(features::intents::DeathIntent))
        };

        auto executeChain = [this](uint32_t id, std::span<const std::type_index> chain, bool stopOnSuccess)
        {
            for (const auto& intentType : chain)
            {
                auto planner = resolver.getPlanner(intentType);
                if (!planner)
                {
                    continue;
                }

                auto intent = planner(*this, id);
                if (!intent)
                {
                    continue;
                }

                if (resolver.resolve(*this, intent) && stopOnSuccess)
                {
                    break;
                }
            }
        };

        for (uint32_t id : ids)
        {
            // Sanity check as Position component is fundamental for the unit's existence
            assert(getComponent<domain::Position>().find(id) != getComponent<domain::Position>().end());

            executeChain(id, maintenanceChain, false);

            auto chainIt = intentsChains.find(id);
            if (chainIt == intentsChains.end())
            {
                continue;
            }

            executeChain(id, chainIt->second.get(), true);
        }

        for (uint32_t id : ids)
        {
            // Sanity check as Position component is fundamental for the unit's existence
            assert(getComponent<domain::Position>().find(id) != getComponent<domain::Position>().end());

            executeChain(id, std::span<const std::type_index>(maintenanceChain).subspan(1, 1), false);
        }
	}
}
