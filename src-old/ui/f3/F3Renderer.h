//
// Created by Adrian on 11/02/2024.
//
#pragma once
#include <amethyst/runtime/events/EventManager.hpp>
#include <amethyst/runtime/HookManager.hpp>
#include <amethyst/runtime/input/InputManager.hpp>
#include <amethyst/runtime/AmethystContext.hpp>
#include "../../per_tick//PerTickHandler.h"
#include "F3State.h"

class F3Renderer{
public:
    AmethystContext* mAmethystContext = nullptr;

private:
    PerTickHandler* mFpsHandler = nullptr;
    PerTickHandler* mTpsHandler = nullptr;
    PerTickHandler* mUpsHandler = nullptr;

public:
    F3State mState = F3State::Basic;

public:
    F3Renderer(AmethystContext* amethystContext);

    void render(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext);

    void onRender();
    void onTick();
    void onUpdate();

private:
    void _renderBasic(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, Vec2 uiScreenSize);
    void _renderModInfo(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, Vec2 uiScreenSize);
    void _renderDimensionInfo(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, Vec2 uiScreenSize);
};
