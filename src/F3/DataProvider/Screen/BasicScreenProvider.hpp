#pragma once
#include "../VersionAmethystProvider.hpp"
#include "../VersionMinecraftProvider.cpp"

class BasicScreenProvider {
private:
    VersionAmethystProvider mVersionAmethystProvider;
    VersionMinecraftProvider mVersionMinecraftProvider;

public:
    std::vector<std::string> obtainData();
};
