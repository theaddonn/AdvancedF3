#include "BasicScreenProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include "minecraft/src-client/common/client/player/LocalPlayer.hpp"
#include "minecraft/src/common/world/phys/Vec2.hpp"

std::vector<std::string> BasicScreenProvider::obtainData()
{
    LocalPlayer* player = Amethyst::GetContext().mClientInstance->getLocalPlayer();
    Vec3* position = player->getPosition();
    Vec2* rotation = player->getHeadRot();

    float cardinalRot = rotation->y + 180.0f;
    std::string direction;

    if (cardinalRot >= 315.0f || cardinalRot < 45.0f)
        direction = "North (Towards -Z)";
    else if (cardinalRot >= 45.0f && cardinalRot < 135.0f)
        direction = "East (Towards +X)";
    else if (cardinalRot >= 135.0f && cardinalRot < 225.0f)
        direction = "South (Towards +Z)";
    else
        direction = "West (Towards -X)";

    return {
        fmt::format("Amethyst Version: {}", this->mVersionAmethystProvider.obtainData()),
        fmt::format("Minecraft Version: {}", this->mVersionMinecraftProvider.obtainData()),
        "",
        fmt::format("Position: [X: {:.2f}; Y: {:.2f}; Z: {:.2f}]", position->x, position->y - 1.62f, position->z),
        fmt::format("Head Rotation: {} [Yaw: {:.2f}; Pitch: {:.2f}]", direction, rotation->x, rotation->y),
        fmt::format("Head-Y: {:.2f}", position->y),
    };
}
