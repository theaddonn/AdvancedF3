#include "F3Renderer.hpp"
#include "minecraft/src-deps/core/math/Color.cpp"

void F3Renderer::RenderTopLeft(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
    for (size_t i = 0; i < text.size(); i++) {

        RectangleArea rect(10, 1000, (i+1)*10);

        TextMeasureData textData(1.0f, 0, true, true, false);
        CaretMeasureData caretData(0, true);

        ctx.drawDebugText(&rect, &text[i], &mce::Color::WHITE, 1.0f, ui::Left, &textData, &caretData);
    }
}

void F3Renderer::RenderTopRight(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
}

void F3Renderer::RenderBottomLeft(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
}

void F3Renderer::RenderBottomRight(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
}
