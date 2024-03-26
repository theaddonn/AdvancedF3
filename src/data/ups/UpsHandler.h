//
// Created by adria on 26/03/2024.
//
#pragma once
#include <chrono>

class UpsHandler {
private:
    std::chrono::milliseconds mUpdateInterval = std::chrono::milliseconds(10000);

private:
    std::chrono::time_point<std::chrono::system_clock> mLastResetTime;
    std::chrono::milliseconds mTotalTime;
    int mCounter;

public:
    void start();
    void update();
    float mUps;
};

