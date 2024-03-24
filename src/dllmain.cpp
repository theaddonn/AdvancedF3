#include "dllmain.h"
#include "recorder/ps_recorder/psRecorder.h"
#include "ui/f3/f3Renderer.h"

bool f3_open = true;

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext* ctx)
{
    // Add a listener to key inputs for opening the f3 screen
    // https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
    //ctx->mInputManager.RegisterNewInput("use_f3", 0x72, true);
    //ctx->mInputManager.("use_f3", &onUseF3);

    // Add a listener to a built-in amethyst event
    //eventManager->onRenderUI.AddListener(&onRenderUi);

    psRecorder::registerEventHandlers(&ctx->mEventManager);

    ctx->mEventManager.onRenderUI.AddListener(&onRenderUi);
}

void onRenderUi(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext)
{
    if (screenView->visualTree->mRootControlName->layerName == "hud_screen" && f3_open) {
        f3Renderer::Renderer(screenView, uiRenderContext);
    }
}

void onUseF3(FocusImpact focus, IClientInstance clientInstance){
    f3_open = !f3_open;
}