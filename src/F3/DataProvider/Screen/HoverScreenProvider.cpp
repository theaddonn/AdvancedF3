#include "HoverScreenProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include "minecraft/src-client/common/client/player/LocalPlayer.hpp"
#include "minecraft/src/common/world/phys/Vec2.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include "minecraft/src-client/common/client/player/LocalPlayer.hpp"
#include "minecraft/src/common/world/phys/Vec2.hpp"

std::array<std::vector<std::string>, 2> HoverScreenProvider::obtainData()
{
    Level* level = Amethyst::GetLevel();

    switch (level->mHitResult.mType) {
    case TILE:
        Log::Info("TILE!");
        break;
    case ENTITY:
        Log::Info("ENTITY!");
        break;
    case ENTITY_OUT_OF_RANGE:
        Log::Info("ENTITY_OUT_OF_RANGE!");
        break;
    case NO_HIT:
        Log::Info("NO_HIT!");
        break;
    default:
        Log::Info("OTHER {}", (int)level->mHitResult.mType);
        break;
    }

    Log::Info("{}", (uint64_t)&level->mHitResult.mType);

    return std::array<std::vector<std::string>, 2>();
}
