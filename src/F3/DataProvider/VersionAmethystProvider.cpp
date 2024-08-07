#include "VersionAmethystProvider.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>

std::string VersionAmethystProvider::obtainData()
{
    [[unlikely]]
    if (!this->mText.has_value()) {
        this->mText = *Amethyst::GetContext().getAmethystVersion();
    }

    return this->mText.value();
}
