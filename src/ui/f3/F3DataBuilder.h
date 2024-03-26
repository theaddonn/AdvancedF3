//
// Created by adria on 12/02/2024.
//
#pragma once
#include <Windows.h>
#include <amethyst/runtime/events/EventManager.h>
#include <amethyst/runtime/HookManager.h>
#include <amethyst/runtime/input/InputManager.h>
#include <amethyst/runtime/AmethystContext.h>
#include "../../data/tps/TpsHandler.h"
#include "../../data/fps/FpsHandler.h"
#include "../../data/ups/UpsHandler.h"

class F3DataBuilder {
public:
    static std::vector<std::string> BuildInfoData(ClientInstance* clientInstance, AmethystContext* amethystContext, FpsHandler* fpsHandler, TpsHandler* tpsHandlerd, UpsHandler* upsHandler);
    static std::vector<std::string> BuildControlData(ClientInstance *clientInstance);
};


