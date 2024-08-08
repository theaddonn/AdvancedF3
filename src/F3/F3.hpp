#pragma once
#include "F3Mode.hpp"
#include "minecraft/src-client/common/client/renderer/screen/MinecraftUIRenderContext.hpp"
#include "DataProvider/Screen/BasicScreenProvider.hpp"
#include "DataProvider/Screen/WorldScreenProvider.hpp"

class F3 {
private:
    F3Mode mMode = F3Mode::World;

    BasicScreenProvider mBasicScreenProvider;
    WorldScreenProvider mDimensionScreenProvider;

public:
    void Render(MinecraftUIRenderContext& ctx);

    void NextMode();
    void PreviousMode();

private:
    void _RenderBasic(MinecraftUIRenderContext& ctx);
    void _RenderWorld(MinecraftUIRenderContext& ctx);
};
