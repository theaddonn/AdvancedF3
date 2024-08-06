//
// Created by Adrian on 12/02/2024.
//
#pragma once
#include <Windows.h>
#include <amethyst/runtime/events/EventManager.hpp>
#include <amethyst/runtime/HookManager.hpp>
#include <amethyst/runtime/input/InputManager.hpp>

// Standardized params for rendering graphics

class UiConfig {
public:
    static int offset;
    static mce::Color background_color;
    static float background_color_alpha;
};


