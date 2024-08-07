#pragma once
#include <vector>
#include <string>
#include "../DimensionIdProvider.hpp"

class DimensionScreenProvider {
private:
    DimensionIdProvider mDimensionIdProvider;

public:
    std::vector<std::string> obtainData();
};
