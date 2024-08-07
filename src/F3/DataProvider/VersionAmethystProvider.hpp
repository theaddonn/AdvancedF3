#pragma once
#include <optional>
#include <string>

class VersionAmethystProvider {
private:
    std::optional<std::string> mText;

public:
    std::string obtainData();
};
