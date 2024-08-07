#pragma once
#include <optional>
#include <string>

class VersionMinecraftProvider {
private:
    std::optional<std::string> mText;

public:
    std::string obtainData();
};
