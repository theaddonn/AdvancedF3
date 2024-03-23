//
// Created by Adrian on 11/02/2024.
//
#pragma once
#include <Windows.h>
#include <amethyst/runtime/events/EventManager.h>
#include <amethyst/runtime/HookManager.h>
#include <amethyst/runtime/input/InputManager.h>

class f3Renderer{
public:
    static void Renderer(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext);
};
