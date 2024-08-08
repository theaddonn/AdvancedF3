#include "F3.hpp"
#include "Render/F3Renderer.hpp"

void F3::Render(MinecraftUIRenderContext& ctx)
{
    switch (this->mMode) {
        case Basic:
            this->_RenderBasic(ctx);
            break;
        case Dimension:
            this->_RenderDimension(ctx);
            break;
    } 

    ctx.flushText(1.0f);
}

void F3::NextMode()
{
    this->mMode = static_cast<F3Mode>((static_cast<int>(this->mMode) + 1) % static_cast<int>(F3Mode::Count));
}

void F3::PreviousMode()
{
    this->mMode = static_cast<F3Mode>((static_cast<int>(this->mMode) - 1 + static_cast<int>(F3Mode::Count)) % static_cast<int>(F3Mode::Count));
}

void F3::_RenderBasic(MinecraftUIRenderContext& ctx)
{
    F3Renderer::RenderTopLeft(ctx, this->mBasicScreenProvider.obtainData());
}

void F3::_RenderDimension(MinecraftUIRenderContext& ctx)
{
    std::array<std::vector<std::string>, 2> worldInfo = this->mDimensionScreenProvider.obtainData();

    F3Renderer::RenderTopLeft(ctx, worldInfo[0]);
    F3Renderer::RenderTopRight(ctx, worldInfo[1]);
}
