#pragma once
#include "F3Mode.hpp"
#include "minecraft/src-client/common/client/renderer/screen/MinecraftUIRenderContext.hpp"
#include "DataProvider/VersionAmethystProvider.hpp"
#include "DataProvider/VersionMinecraftProvider.hpp"

class F3 {
public:
    F3();

private:
    F3Mode mMode;
    VersionAmethystProvider mVersionAmethystProvider;
    VersionMinecraftProvider mVersionMinecraftProvider;

public:
    void Render(MinecraftUIRenderContext& ctx);

private:
    void _RenderBasic(MinecraftUIRenderContext& ctx);
};
