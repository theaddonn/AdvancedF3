#pragma once
#include <Windows.h>
#include <amethyst/runtime/AmethystContext.h>

#include <iomanip>
#include <iostream>
#include <vector>

#define ModFunction extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}

void onRenderUi(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext);
void onUpdate();

void onUseF3(FocusImpact focus, IClientInstance clientInstance);