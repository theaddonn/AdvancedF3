#include "dllmain.h"
#include "ui/f3/F3Renderer.h"

bool f3_open = false;
bool ctrl_pressed = false;
F3Renderer* F3 = nullptr;

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext* ctx)
{
    F3 = new F3Renderer(ctx);

    // Add a listener to a built-in amethyst event
    ctx->mEventManager.registerInputs.AddListener(&onRegisterInputs);

    ctx->mEventManager.onStartJoinGame.AddListener(&onStartJoinGame);

    ctx->mEventManager.beforeRenderUI.AddListener(&afterRenderUI);
    ctx->mEventManager.update.AddListener(&onUpdate);
}

void onRegisterInputs(Amethyst::InputManager* inputManager){
    // Add a listener to key inputs for opening the f3 screen
    // https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
    inputManager->RegisterNewInput("f3_use", {0x72 /* F3 */}, true);

    inputManager->RegisterNewInput("f3_ctrl", {0x11 /* CTRL */}, true);

    inputManager->RegisterNewInput("f3_open_basic", {0x48 /* H */}, true);
    inputManager->RegisterNewInput("f3_open_mods", {0x4D /* M */}, true);
    inputManager->RegisterNewInput("f3_open_dim", {0x47 /* M */}, true);

    inputManager->RegisterNewInput("f3_next", {0x4E /* N */}, true);
}

void onStartJoinGame(ClientInstance* instance) {
    F3->mAmethystContext->mInputManager.AddButtonDownHandler("f3_use", &onF3Use, true);

    F3->mAmethystContext->mInputManager.AddButtonDownHandler("f3_ctrl", &onF3CtrlDOWN, true);
    F3->mAmethystContext->mInputManager.AddButtonUpHandler("f3_ctrl", &onF3CtrlUP, true);

    F3->mAmethystContext->mInputManager.AddButtonDownHandler("f3_open_basic", &onF3OpenBasic, true);
    F3->mAmethystContext->mInputManager.AddButtonDownHandler("f3_open_mods", &onF3OpenMods, true);
    F3->mAmethystContext->mInputManager.AddButtonDownHandler("f3_open_dim", &onF3OpenDim, true);

    F3->mAmethystContext->mInputManager.AddButtonDownHandler("f3_next", &onF3Next, true);
}

void afterRenderUI(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext)
{
    // Don't render if player isn't in world
    if (uiRenderContext->mClient->getRegion() == nullptr) return;

    if (F3 == nullptr) return;

    if ((screenView->visualTree->mRootUiControl->mName == "hud_screen") && f3_open) {
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

void onF3Use(FocusImpact _focus, IClientInstance _clientInstance)
{
    Log::Info("F3");
    f3_open = !f3_open;
}

void onF3CtrlDOWN(FocusImpact _focus, IClientInstance _clientInstance)
{
    Log::Info("CTRL DOWN");
    ctrl_pressed = true;
}

void onF3CtrlUP(FocusImpact _focus, IClientInstance _clientInstance)
{
    Log::Info("CTRL UP");
    ctrl_pressed = false;
}

void onF3OpenBasic(FocusImpact _focus, IClientInstance _clientInstance)
{
    if (ctrl_pressed && f3_open) {
        F3->mState = F3State::Basic;
    }
}

void onF3OpenMods(FocusImpact _focus, IClientInstance _clientInstance)
{
    if (ctrl_pressed && f3_open) {
        F3->mState = F3State::ModsInfo;
    }
}

void onF3OpenDim(FocusImpact _focus, IClientInstance _clientInstance)
{
    if (ctrl_pressed && f3_open) {
        F3->mState = F3State::DimensionInfo;
    }
}

void onF3Next(FocusImpact _focus, IClientInstance _clientInstance)
{
    Log::Info("F3 next");

    if (ctrl_pressed && f3_open) {

        auto state = static_cast<F3State>(static_cast<uint16_t>(F3->mState) + 1);

        if (state >= F3State::Count) {
            F3->mState = F3State::Basic;
        }
        else {
            F3->mState = state;
        }
    }
}