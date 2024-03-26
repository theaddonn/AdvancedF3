//
// Created by adria on 26/03/2024.
//

#include "UpsHandler.h"

void UpsHandler::start() {
    this->mTotalTime = std::chrono::milliseconds(0);
    this->mLastResetTime = std::chrono::system_clock::now();
}

void UpsHandler::update() {
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

        float ups = static_cast<float>(this->mCounter) / (static_cast<float>(millis) / 1000);

        this->mUps = ups;

        this->mTotalTime = std::chrono::milliseconds(0);
        this->mLastResetTime = std::chrono::system_clock::now();
        this->mCounter = 0;
    }
}

