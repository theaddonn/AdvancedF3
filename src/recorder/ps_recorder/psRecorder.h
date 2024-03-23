//
// Created by Adrian on 12/02/2024.
//
#pragma once
#include <Windows.h>
#include <amethyst/runtime/events/EventManager.h>
#include <amethyst/runtime/HookManager.h>
#include <amethyst/runtime/input/InputManager.h>


class psRecorder {
public:
    static void registerEventHandlers(Amethyst::EventManager* eventManager);
    static Vec3 getData();
private:
    static void onTick();
    static void onRenderUI(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext);
    static void onUpdate();
};


