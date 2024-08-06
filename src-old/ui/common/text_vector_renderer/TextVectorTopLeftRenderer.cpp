//
// Created by adria on 14/02/2024.
//

#include "TextVectorRenderer.h"
#include "../../config/UiConfig.h"

void TextVectorRenderer::TextVectorTopLeftRenderer(ScreenView *screenView, MinecraftUIRenderContext *uiRenderContext, std::vector<std::string> data, Vec2 uiScreenSize){
    int offset = UiConfig::offset;
    mce::Color color = UiConfig::background_color;

    auto textMeasureData = TextMeasureData(
            1.0f,
            1,
            false,
            false,
            false
    );

    auto caretMeasureData = CaretMeasureData(
            1,
            false
    );

    for (int i = 0; i < data.size(); ++i) {
        if (data[i].empty()){
            continue;
        }

        auto area = RectangleArea(
                static_cast<float>(offset) * 2,
                1000.0f,
                static_cast<float>(i) * 10 + offset * 2,
                1000.0f
        );

        uiRenderContext->drawDebugText(
                &area,
                &data[i],
                &mce::Color::WHITE,
                1,
                ui::TextAlignment::Left,
                &textMeasureData,
                &caretMeasureData
                );
    }
}