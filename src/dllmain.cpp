#include "dllmain.h"
#include "recorder/ps_recorder/psRecorder.h"
#include "ui/f3/f3Renderer.h"

bool f3_open = true;

SafetyHookInline Dimension_Dimension_Hook;

union DimensionHeightRange
{
    uint32_t packed;
    struct
    {
        int16_t min;
        int16_t max;
    };
};

uint32_t makeHeightRange(uint16_t max, uint16_t min)
{
    return ((max & 0xFFFF) << 16) | (min & 0xFFFF);
}

void* Dimension_Dimension(void* self, void* a2, int dimensionID, DimensionHeightRange HeightRange, void* a5, std::string* dimName)
{
    HeightRange.min = -1024;
    HeightRange.max = 1024;
    return Dimension_Dimension_Hook.fastcall<void*>(self, a2, dimensionID, HeightRange, a5, dimName);
}

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

    //ctx->mHookManager.RegisterFunction<Dimension_Dimension>("48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 41 8B F9 41 8B D8");
    //ctx->mHookManager.CreateHook<&Dimension_Dimension>(Dimension_Dimension_Hook, Dimension_Dimension);

    for (const auto& mod : *ctx->mMods) {
        Log::Info("\n============== FOUND A MOD ==============\n");
        Log::Info("{}", "{");
        Log::Info("     \"name\": \"{}\",", mod.metaData.name);
        Log::Info("     \"author\": [");

        for (const auto& author : mod.metaData.author) {
            Log::Info("             \"{}\",", author);
        }
        Log::Info("     ],");
        Log::Info("     \"version\": {}", mod.metaData.version);
        Log::Info("{}", "}");
    }

    ctx->mEventManager.onRenderUI.AddListener(&onRenderUi);
}

void onRenderUi(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext)
{
    Log::Info("NAME: {}", screenView->visualTree->mRootControlName->layerName);
    if (screenView->visualTree->mRootControlName->layerName == "hud_screen" && f3_open) {
        f3Renderer::Renderer(screenView, uiRenderContext);
    }
}

void onUseF3(FocusImpact focus, IClientInstance clientInstance){
    f3_open = !f3_open;
}