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

void F3::_RenderBasic(MinecraftUIRenderContext& ctx)
{
    F3Renderer::RenderTopLeft(ctx, this->mBasicScreenProvider.obtainData());
}

void F3::_RenderDimension(MinecraftUIRenderContext& ctx)
{
    F3Renderer::RenderTopLeft(ctx, this->mDimensionScreenProvider.obtainData());
}
