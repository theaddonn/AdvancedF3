#include "F3Renderer.hpp"
#include "minecraft/src-deps/core/math/Color.cpp"
#include "minecraft/src-client/common/client/game/ClientInstance.hpp"
#include "minecraft/src-client/common/client/gui/gui/GuiData.hpp"
#include <amethyst/runtime/AmethystContext.hpp>
#include <amethyst/runtime/ModContext.hpp>

const int LINE_SEPERATOR_SIZE = 10;
const int LINE_SEPERATOR_PADDING = 2;
const int BORDER_PADDING_SIZE = 20;

void F3Renderer::RenderTopLeft(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
    Vec2 screenSize = ctx.mClient->guiData->clientUIScreenSize;

    for (size_t i = 0; i < text.size(); i++) {

        RectangleArea rect(BORDER_PADDING_SIZE, screenSize.x, (i + 1) * (LINE_SEPERATOR_SIZE + LINE_SEPERATOR_PADDING), screenSize.y);

        TextMeasureData textData(1.0f, 0, true, true, false);
        CaretMeasureData caretData(0, true);

        ctx.drawDebugText(rect, text[i], mce::Color::WHITE, 1.0f, ui::Left, textData, caretData);
    }
}

void F3Renderer::RenderTopRight(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
    Vec2 screenSize = ctx.mClient->guiData->clientUIScreenSize;

    for (size_t i = 0; i < text.size(); i++) {

        RectangleArea rect(400, screenSize.x, (i + 1) * (LINE_SEPERATOR_SIZE + LINE_SEPERATOR_PADDING), screenSize.y);

        TextMeasureData textData(1.0f, 0, true, true, false);
        CaretMeasureData caretData(0, true);

        ctx.drawDebugText(rect, text[i], mce::Color::WHITE, 1.0f, ui::Right, textData, caretData);
    }
}

void F3Renderer::RenderBottomLeft(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
}

void F3Renderer::RenderBottomRight(MinecraftUIRenderContext& ctx, std::vector<std::string> text)
{
}
