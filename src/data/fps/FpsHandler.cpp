//
// Created by adria on 26/03/2024.
//

#include "FpsHandler.h"
#include <chrono>

void FpsHandler::start() {
    this->mTotalTime = std::chrono::milliseconds(0);
    this->mLastResetTime = std::chrono::system_clock::now();
}

void FpsHandler::update() {
    auto currentTime = std::chrono::system_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - this->mLastResetTime);

    this->mTotalTime += elapsedTime;
    this->mCounter++;

    // Assuming mUpdateInterval is properly defined and initialized
    if (this->mTotalTime >= mUpdateInterval)
    {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        auto duration = now - this->mLastResetTime;
        auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

        float fps = static_cast<float>(this->mCounter) / (static_cast<float>(millis) / 1000);

        this->mFps = fps;

        this->mTotalTime = std::chrono::milliseconds(0);
        this->mLastResetTime = std::chrono::system_clock::now();
        this->mCounter = 0;
    }
}
