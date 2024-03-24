//
// Created by adria on 12/02/2024.
//
#pragma once
#include <Windows.h>
#include <amethyst/runtime/events/EventManager.h>
#include <amethyst/runtime/HookManager.h>
#include <amethyst/runtime/input/InputManager.h>
#include <amethyst/runtime/AmethystContext.h>

class f3DataBuilder {
public:
    static std::vector<std::string> BuildInfoData(ClientInstance* clientInstance, AmethystContext* amethystContext);
    static std::vector<std::string> BuildControlData(ClientInstance *clientInstance);
};


