#include "DimensionIdProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>

int DimensionIdProvider::obtainData()
{
    return Amethyst::GetContext().mClientInstance->getRegion()->getDimension().mId.runtimeID;
}
