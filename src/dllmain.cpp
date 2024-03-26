#include "dllmain.h"
#include "ui/f3/F3Renderer.h"

bool f3_open = true;
AmethystContext* amethystContext = nullptr;
F3Renderer* F3 = nullptr;

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext* ctx)
{
    Log::Info("BF IN");
    // Add a listener to key inputs for opening the f3 screen
    // https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
    //ctx->mInputManager.RegisterNewInput("use_f3", 0x72, true);
    //ctx->mInputManager.("use_f3", &onUseF3);

    amethystContext = ctx;

    F3 = new F3Renderer();

    // Add a listener to a built-in amethyst event
    ctx->mEventManager.onRenderUI.AddListener(&onRenderUi);
    //ctx->mEventManager.update.AddListener(&onUpdate);
}

void onRenderUi(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext)
{
    if (F3 == nullptr) return;
    if (screenView->visualTree->mRootControlName->layerName == "hud_screen" && f3_open) {
        F3->onRender();
        F3->onTick();
        F3->onUpdate();

        F3->render(screenView, uiRenderContext, amethystContext);
    }
}

void onUpdate()
{
    if (F3 == nullptr) return;
}

void onUseF3(FocusImpact _focus, IClientInstance _clientInstance)
{
    f3_open = !f3_open;
}