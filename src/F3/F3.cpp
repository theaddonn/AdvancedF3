#include "F3.hpp"
#include "Render/F3Renderer.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>

void F3::Render(MinecraftUIRenderContext& ctx)
{
    switch (this->mMode) {
        case BasicMode:
            this->_RenderBasic(ctx);
            break;
        case WorldMode:
            this->_RenderWorld(ctx);
            break;
        case AmethystMode:
            this->_RenderAmethyst(ctx);
            break;
        case HoverMode:
            this->_RenderHover(ctx);
            break;
    } 

    ctx.flushText(1.0f);
}

void F3::NextMode()
{
    this->mMode = static_cast<F3Mode>((static_cast<int>(this->mMode) + 1) % static_cast<int>(F3Mode::Count));
}

void F3::PrevMode()
{
    this->mMode = static_cast<F3Mode>((static_cast<int>(this->mMode) - 1 + static_cast<int>(F3Mode::Count)) % static_cast<int>(F3Mode::Count));
}

void F3::_RenderBasic(MinecraftUIRenderContext& ctx)
{
    F3Renderer::RenderTopLeft(ctx, this->mBasicScreenProvider.obtainData());
}

void F3::_RenderWorld(MinecraftUIRenderContext& ctx)
{
    std::array<std::vector<std::string>, 2> worldInfo = this->mDimensionScreenProvider.obtainData();

    F3Renderer::RenderTopLeft(ctx, worldInfo[0]);
    F3Renderer::RenderTopRight(ctx, worldInfo[1]);
}

void F3::_RenderAmethyst(MinecraftUIRenderContext& ctx)
{
    F3Renderer::RenderTopLeft(ctx, this->mAmethystScreenProvider.obtainData());
}

void F3::_RenderHover(MinecraftUIRenderContext& ctx)
{
    Log::Info("Render Hover!");

    std::array<std::vector<std::string>, 2> hoverInfo = this->mHoverScreenProvider.obtainData();

    F3Renderer::RenderTopLeft(ctx, hoverInfo[0]);
    F3Renderer::RenderTopRight(ctx, hoverInfo[1]);
}
