#pragma once
#include <vector>
#include <string>
#include "../VersionAmethystProvider.hpp"
#include "../VersionMinecraftProvider.hpp"

class BasicScreenProvider {
private:
    VersionAmethystProvider mVersionAmethystProvider;
    VersionMinecraftProvider mVersionMinecraftProvider;

public:
    std::vector<std::string> obtainData();
};
