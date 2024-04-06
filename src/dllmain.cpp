#include "dllmain.h"
#include "ui/f3/F3Renderer.h"
#include "minecraft/src-client/common/client/gui/controls/ToggleComponent.hpp"
#include "minecraft/src/common/world/level/BlockPos.hpp"

bool f3_open = true;
F3Renderer* F3 = nullptr;
int frame = 0;

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext* ctx)
{
    // Add a listener to key inputs for opening the f3 screen
    // https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
    //ctx->mInputManager.RegisterNewInput("use_f3", 0x72, true);
    //ctx->mInputManager.("use_f3", &onUseF3);

    F3 = new F3Renderer(ctx);

    // Add a listener to a built-in amethyst event
    ctx->mEventManager.beforeRenderUI.AddListener(&afterRenderUI);
    ctx->mEventManager.update.AddListener(&onUpdate);
}


void afterRenderUI(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext)
{
    // Don't render if player isn't in world
    if (uiRenderContext->mClient->getRegion() == nullptr) return;

    if (F3 == nullptr) return;

    if ((screenView->visualTree->mRootUiControl->mName == "hud_screen") && f3_open) {
        frame++;

        if (frame % 300 == 0) {
            switch (F3->mState) {
                case Basic:
                    F3->mState = F3State::ModsInfo;
                    break;
                case ModsInfo:
                    F3->mState = F3State::DimensionInfo;
                    break;
                case DimensionInfo:
                    F3->mState = F3State::Basic;
                    break;
            };
            frame = 0;
        }

        F3->onRender();
        F3->onTick();

        F3->render(screenView, uiRenderContext);
    }
}

void onUpdate()
{
    if (F3 == nullptr) return;

    F3->onUpdate();
}

void onUseF3(FocusImpact _focus, IClientInstance _clientInstance)
{
    f3_open = !f3_open;
}