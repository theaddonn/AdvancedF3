#include "DimensionScreenProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>

std::vector<std::string> DimensionScreenProvider::obtainData()
{
    BlockSource* region = Amethyst::GetContext().mClientInstance->getRegion();
    const Dimension* dimension = &region->getDimensionConst();
    auto spawnPos = dimension->getSpawnPos();

    const Level& level = dimension->getLevelConst();

    return {
        fmt::format("Dimension Name: {}", dimension->mName),
        fmt::format("Dimension ID: {}", this->mDimensionIdProvider.obtainData()),
        "",
        fmt::format("Dimension DefaultBiome: {}", dimension->getDefaultBiome().getString()),
        fmt::format("Dimension SpawnPos [X: {}; Y: {}; Z: {}]", spawnPos.x, spawnPos.y, spawnPos.z),
        fmt::format("Dimension HasGround: {}", dimension->hasGround()),
        fmt::format("Dimension HasPrecipitationFog: {}", dimension->hasPrecipitationFog()),
        fmt::format("Dimension IsDay: {}", dimension->isDay()),
        fmt::format("Dimension MayRespawnViaBed: {}", dimension->mayRespawnViaBed()),
        fmt::format("Dimension HasCeiling: {}", dimension->mHasCeiling),
        fmt::format("Dimension HasSkylight: {}", dimension->mHasSkylight),
        fmt::format("Dimension HasWeather: {}", dimension->mHasWeather),
        fmt::format("Dimension RunChunkGenWatchDog: {}", dimension->mRunChunkGenWatchDog),
        fmt::format("Dimension SeaLevel: {}", dimension->mSeaLevel),
        fmt::format("Dimension UltraWarm: {}", dimension->mUltraWarm),
        fmt::format("Dimension HeightRange: [Max: {}; Min: {}]", dimension->mHeightRange.mMax, dimension->mHeightRange.mMin),
        fmt::format("Dimension IsNaturalDimension: {}", dimension->isNaturalDimension()),
        fmt::format("Dimension CloudHeight: {}", dimension->getCloudHeight()),
        fmt::format("Dimension CIRCUIT_TICK_RATE: {}", dimension->CIRCUIT_TICK_RATE),
        "",
        "",
        fmt::format("Level IsClientSide: {}", level.isClientSide),
        fmt::format("Level IsEditorWorld: {}", level.isEditorWorld()),
        fmt::format("Level IsEdu: {}", level.isEdu()),
        fmt::format("Level IsExporting: {}", level.isExporting()),
        fmt::format("Level IsMultiplayerGame: {}", level.isMultiplayerGame()),
        fmt::format("Level ActivePlayerCount: {}", level.getActivePlayerCount()),
        fmt::format("Level ActiveUsersCount: {}", level.getActiveUsersCount()),
        fmt::format("Level UserCount: {}", level.getUserCount()),
        fmt::format("Level CurrentServerTick: {}", level.getCurrentServerTick().tickID),
        fmt::format("Level CurrentTick: {}", level.getCurrentTick().tickID),
        fmt::format("Level NetherScale: {}", level.getNetherScale()),
        fmt::format("Level Time: {}", level.getTime()),
        fmt::format("Level HasCommandsEnabled: {}", level.hasCommandsEnabled()),
        fmt::format("Level HasLevelStorage: {}", level.hasLevelStorage()),
        fmt::format("Level HasStartWithMapEnabled: {}", level.hasStartWithMapEnabled()),
        fmt::format("Level HasPlatformBroadcast: {}", level.hasPlatformBroadcast()),
        fmt::format("Level HasPlatformBroadcastIntent: {}", level.hasPlatformBroadcastIntent()),
        fmt::format("Level HasXBLBroadcast: {}", level.hasXBLBroadcast()),
        fmt::format("Level HasXBLBroadcastIntent: {}", level.hasXBLBroadcastIntent()),
        "",
        "",
        fmt::format("Region CanDoBlockDrops: {}", region->canDoBlockDrops()),
        fmt::format("Region CanDoContainedItemDrops: {}", region->canDoContainedItemDrops()),
        fmt::format("Region AllowUnpopulatedChunks: {}", region->mAllowUnpopulatedChunks),
        fmt::format("Region CheckValidity: {}", region->mCheckValidity),
    };
}
