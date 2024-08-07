#pragma once
#include "F3Mode.hpp"
#include "minecraft/src-client/common/client/renderer/screen/MinecraftUIRenderContext.hpp"
#include "DataProvider/Screen/BasicScreenProvider.hpp"
#include "DataProvider/Screen/DimensionScreenProvider.hpp"

class F3 {
private:
    F3Mode mMode = F3Mode::Basic;

    BasicScreenProvider mBasicScreenProvider;
    DimensionScreenProvider mDimensionScreenProvider;

public:
    void Render(MinecraftUIRenderContext& ctx);

private:
    void _RenderBasic(MinecraftUIRenderContext& ctx);
    void _RenderDimension(MinecraftUIRenderContext& ctx);
};
