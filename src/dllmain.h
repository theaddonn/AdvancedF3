#pragma once
#include <Windows.h>
#include <amethyst/runtime/AmethystContext.hpp>

#include <iomanip>
#include <iostream>
#include <vector>

#define ModFunction extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}

void onRegisterInputs(Amethyst::InputManager* inputManager);

void onStartJoinGame(ClientInstance* instance);

void afterRenderUI(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext);
void onUpdate();

void onF3Use(FocusImpact _focus, IClientInstance _clientInstance);
void onF3CtrlDOWN(FocusImpact _focus, IClientInstance _clientInstance);
void onF3CtrlUP(FocusImpact _focus, IClientInstance _clientInstance);

void onF3OpenBasic(FocusImpact _focus, IClientInstance _clientInstance);
void onF3OpenMods(FocusImpact _focus, IClientInstance _clientInstance);
void onF3OpenDim(FocusImpact _focus, IClientInstance _clientInstance);

void onF3Next(FocusImpact _focus, IClientInstance _clientInstance);