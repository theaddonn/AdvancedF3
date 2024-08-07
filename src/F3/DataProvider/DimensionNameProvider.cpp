#include "DimensionNameProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>

std::string DimensionNameProvider::obtainData()
{
    return Amethyst::GetContext().mClientInstance->getRegion()->getDimension().mName;
}
