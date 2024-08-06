//
// Created by adria on 12/02/2024.
//
#pragma once
#include <Windows.h>
#include <amethyst/runtime/events/EventManager.hpp>
#include <amethyst/runtime/HookManager.hpp>
#include <amethyst/runtime/input/InputManager.hpp>
#include <amethyst/runtime/AmethystContext.hpp>
#include "../../per_tick/PerTickHandler.h"

class F3DataBuilder {
public:
    static std::vector<std::string> BuildInfoData(ClientInstance* clientInstance, AmethystContext* amethystContext, PerTickHandler* fpsHandler, PerTickHandler* tpsHandlerd, PerTickHandler* upsHandler);
    static std::vector<std::string> BuildControlData(ClientInstance *clientInstance);
    static std::vector<std::string> BuildModInfoData(AmethystContext* amethystContext);
    static std::vector<std::string> BuildDimensionInfoData(ClientInstance* clientInstance);
};


