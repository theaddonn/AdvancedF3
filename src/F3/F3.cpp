#include "F3.hpp"
#include "minecraft/src-deps/core/math/Color.cpp"

void F3::Render(MinecraftUIRenderContext& ctx)
{
    RectangleArea area(10, 100, 10, 100);

    std::string text = "Hello World!";

    TextMeasureData textData(1.0f, 0, false, true, false);

    CaretMeasureData caretData(0, true);

    ctx.drawDebugText(&area, &text, &mce::Color::WHITE, 1.0f, ui::TextAlignment::Center, &textData, &caretData);

    ctx.flushText(1.0f);
}
