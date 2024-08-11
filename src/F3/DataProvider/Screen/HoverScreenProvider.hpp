#pragma once
#include "../DimensionIdProvider.hpp"
#include "../DimensionNameProvider.hpp"
#include <string>
#include <vector>

class HoverScreenProvider {

public:
    std::array<std::vector<std::string>, 2> obtainData();
};
