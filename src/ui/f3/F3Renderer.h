//
// Created by Adrian on 11/02/2024.
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

class F3Renderer{
private:
    FpsHandler* mFpsHandler = nullptr;
    TpsHandler* mTpsHandler = nullptr;
    UpsHandler* mUpsHandler = nullptr;
public:
    void render(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, AmethystContext* amethystContext);

    void onRender();
    void onTick();
    void onUpdate();
};
