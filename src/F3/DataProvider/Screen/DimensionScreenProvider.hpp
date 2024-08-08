#pragma once
#include <vector>
#include <string>
#include "../DimensionIdProvider.hpp"
#include "../DimensionNameProvider.hpp"

class DimensionScreenProvider {
private:
    DimensionIdProvider mDimensionIdProvider;
    DimensionNameProvider mDimensionNameProvider;

public:
    std::array<std::vector<std::string>, 2> obtainData();
};
