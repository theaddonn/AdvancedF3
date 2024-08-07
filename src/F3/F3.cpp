#include "F3.hpp"
#include "Render/F3Renderer.hpp"

F3::F3()
{
    this->mMode = F3Mode::Basic;
}

void F3::Render(MinecraftUIRenderContext& ctx)
{
    switch (this->mMode) {
        case Basic:
            this->_RenderBasic(ctx);
            break;
        
    } 

    ctx.flushText(1.0f);
}

void F3::_RenderBasic(MinecraftUIRenderContext& ctx)
{
    std::vector<std::string> texts = {
        this->mVersionAmethystProvider.obtainData(),
        this->mVersionMinecraftProvider.obtainData(),
        "",

        };

    F3Renderer::RenderTopLeft(ctx, texts);
}
