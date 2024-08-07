#include "VersionMinecraftProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>

std::string& VersionMinecraftProvider::obtainData()
{
    [[unlikely]]
    if (!this->mText.has_value()) {
        this->mText = fmt::format("Minecraft Version: {}", Amethyst::MinecraftPackageInfo().mVersion.mFullVersionString);
    }

    return this->mText.value();
}
