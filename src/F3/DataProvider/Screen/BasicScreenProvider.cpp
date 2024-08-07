#include "BasicScreenProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>

std::vector<std::string> BasicScreenProvider::obtainData()
{
    return {
         fmt::format("Amethyst Version: {}", this->mVersionAmethystProvider.obtainData()),
         fmt::format("Minecraft Version: {}", this->mVersionMinecraftProvider.obtainData()),
    };
}
