#include "AmethystScreenProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include <minecraft/src/common/world/level/dimension/Dimension.hpp>
#include <minecraft/src/common/world/level/BlockSource.hpp>
#include "minecraft/src-client/common/client/player/LocalPlayer.hpp"
#include "minecraft/src/common/world/phys/Vec2.hpp"

std::vector<std::string> AmethystScreenProvider::obtainData()
{   
    std::vector<std::string> text = {
        fmt::format("Amethyst Version: {}", this->mVersionAmethystProvider.obtainData()),
        fmt::format("Minecraft Version: {}", this->mVersionMinecraftProvider.obtainData()),
        fmt::format("Minecraft Target Version: {}", Amethyst::GetContext().getTargetVersion()->mFullVersionString),
        "",
        "Mods:"
    };

    for (auto mod : Amethyst::GetContext().mMods) {
        text.push_back(fmt::format("   {} (by {})", mod.modName, fmt::join(mod.metadata.author, ", ")));
    }

    return text;
}
