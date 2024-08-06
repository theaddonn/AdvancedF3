//
// Created by adria on 14/02/2024.
//

#include "TextVectorRenderer.h"
#include "../../config/UiConfig.h"

void TextVectorRenderer::TextVectorBottomRightRenderer(ScreenView *screenView, MinecraftUIRenderContext *uiRenderContext, std::vector<std::string> data, Vec2 uiScreenSize) {
    int offset = UiConfig::offset;
    mce::Color color = UiConfig::background_color;

    int targetStringSize = 0;

    for (const auto & i : data) {
        if (static_cast<int>(i.length()) > targetStringSize ){
            targetStringSize = static_cast<int>(i.length());
        }
    }

    float height = static_cast<float>(data.size()) * 10;

    auto textMeasureData = TextMeasureData(
            1.0f,
            1,
            false,
            false,
            false
    );

    auto caretMeasureData = CaretMeasureData(
            1,
            true
    );

    for (int i = 0; i < data.size(); ++i) {
        if (data[i].empty()){
            continue;
        }

        auto area = RectangleArea(
                uiScreenSize.x - (static_cast<float>(offset) * 2) - (static_cast<float>(targetStringSize) * 5),
                uiScreenSize.x - (static_cast<float>(offset) * 2),
                uiScreenSize.y - height - (static_cast<float>(offset) * 2) + (static_cast<float>(i * 10)),
                1000.0f
        );

        uiRenderContext->drawDebugText(
                &area,
                &data[i],
                &mce::Color::WHITE,
                1.0f,
                ui::TextAlignment::Right,
                &textMeasureData,
                &caretMeasureData
                );
    }
}
