#include "dllmain.hpp"
#include "F3/F3.hpp"
#include <minecraft/src-client/common/client/gui/ScreenView.hpp>
#include <minecraft/src-client/common/client/gui/gui/UIControl.hpp>
#include <minecraft/src-client/common/client/gui/gui/VisualTree.hpp>

F3 f3;
bool f3Open = false;

ModFunction void Initialize(AmethystContext& ctx)
{
    // Initialize Amethyst mod backend
    Amethyst::InitializeAmethystMod(ctx);
    
    // Enable input system
    Amethyst::GetContext().mFeatures->enableInputSystem = true;
    
    // Add event listeners
    Amethyst::GetEventBus().AddListener<AfterRenderUIEvent>(onRenderUI);
    Amethyst::GetEventBus().AddListener<RegisterInputsEvent>(onRegisterInputs);
    Amethyst::GetEventBus().AddListener<OnStartJoinGameEvent>(onStartJoinGame);
}

void onRenderUI(AfterRenderUIEvent& event)
{
    if (f3Open && event.screen.visualTree->mRootControlName->mName == "hud_screen") {
        f3.Render(event.ctx);
    }
}

void onRegisterInputs(RegisterInputsEvent event)
{
    event.inputManager.RegisterNewInput("f3", {VK_F3 /* F3 */});
    event.inputManager.RegisterNewInput("f3_next", {VK_RIGHT /*Right arrow*/});
    event.inputManager.RegisterNewInput("f3_prev", {VK_LEFT /*Left arrow*/});
}

void onStartJoinGame(OnStartJoinGameEvent event)
{
    Amethyst::GetContext().mInputManager->AddButtonDownHandler("f3", buttonHandlerF3, false);
    Amethyst::GetContext().mInputManager->AddButtonDownHandler("f3_next", buttonHandlerF3Next, false);
    Amethyst::GetContext().mInputManager->AddButtonDownHandler("f3_prev", buttonHandlerF3Prev, false);
}

void buttonHandlerF3(FocusImpact focus, IClientInstance& client)
{
    f3Open = !f3Open;
}

void buttonHandlerF3Next(FocusImpact focus, IClientInstance& client)
{
    if (f3Open) {
        f3.NextMode();
    }
}

void buttonHandlerF3Prev(FocusImpact focus, IClientInstance& client)
{
    if (f3Open) {
        f3.PrevMode();
    }
}
