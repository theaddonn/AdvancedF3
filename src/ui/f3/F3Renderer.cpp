//
// Created by Adrian on 11/02/2024.
//

#include "F3Renderer.h"
#include "F3DataBuilder.h"
#include "../common/text_vector_renderer/TextVectorRenderer.h"
#include <vector>

void F3Renderer::render(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, AmethystContext* amethystContext) {
    ClientInstance* clientInstance = uiRenderContext->mClient;

    // Don't render unless in world
    if (clientInstance->getLocalPlayer() == nullptr) return;

    std::vector<std::string> extra_data = {
            "GPU: Nvidia 4090 TI Super",
            "CPU: Intel i9 15700K",
            "RAM: 67/128GB (52%)"
    };

    std::vector<std::string> tool_tips = {
            "§bIf you press alt+F4",
            "§byou get free diamonds."
    };

    Vec2 uiScreenSize = clientInstance->guiData->clientUIScreenSize;

    TextVectorRenderer::TextVectorTopLeftRenderer(screenView, uiRenderContext, F3DataBuilder::BuildInfoData(clientInstance, amethystContext, this->mFpsHandler, this->mTpsHandler, this->mUpsHandler), uiScreenSize);
    TextVectorRenderer::TextVectorTopRightRenderer(screenView, uiRenderContext, F3DataBuilder::BuildControlData(clientInstance), uiScreenSize);

    TextVectorRenderer::TextVectorBottomLeftRenderer(screenView, uiRenderContext, extra_data, uiScreenSize);
    TextVectorRenderer::TextVectorBottomRightRenderer(screenView, uiRenderContext, tool_tips, uiScreenSize);
}

void F3Renderer::onRender() {
    if (this->mFpsHandler == nullptr)
    {
        this->mFpsHandler = new FpsHandler();
        this->mFpsHandler->start();
    }
    this->mFpsHandler->update();
}

void F3Renderer::onTick() {
    if (this->mTpsHandler == nullptr)
    {
        this->mTpsHandler = new TpsHandler();
        this->mTpsHandler->start();
    }
    this->mTpsHandler->update();
}

void F3Renderer::onUpdate() {
    if (this->mUpsHandler == nullptr)
    {
        this->mUpsHandler = new UpsHandler();
        this->mUpsHandler->start();
    }
    this->mUpsHandler->update();
}