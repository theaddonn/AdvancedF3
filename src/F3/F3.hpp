#pragma once
#include "F3Mode.hpp"
#include "minecraft/src-client/common/client/renderer/screen/MinecraftUIRenderContext.hpp"
#include "DataProvider/Screen/BasicScreenProvider.hpp"
#include "DataProvider/Screen/WorldScreenProvider.hpp"
#include "DataProvider/Screen/AmethystScreenProvider.hpp"
#include "DataProvider/Screen/HoverScreenProvider.hpp"

class F3 {
private:
    F3Mode mMode = F3Mode::AmethystMode;

    BasicScreenProvider mBasicScreenProvider;
    WorldScreenProvider mDimensionScreenProvider;
    AmethystScreenProvider mAmethystScreenProvider;
    HoverScreenProvider mHoverScreenProvider;

public:
    void Render(MinecraftUIRenderContext& ctx);

    void NextMode();
    void PrevMode();

private:
    void _RenderBasic(MinecraftUIRenderContext& ctx);
    void _RenderWorld(MinecraftUIRenderContext& ctx);
    void _RenderAmethyst(MinecraftUIRenderContext& ctx);
    void _RenderHover(MinecraftUIRenderContext& ctx);
};
