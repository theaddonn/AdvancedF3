//
// Created by Adrian on 11/02/2024.
//

#include "F3Renderer.h"
#include "F3DataBuilder.h"
#include "../common/text_vector_renderer/TextVectorRenderer.h"
#include <vector>

F3Renderer::F3Renderer(AmethystContext *amethystContext) {
    this->mAmethystContext = amethystContext;
}

void F3Renderer::render(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext) {
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

    switch (this->mState) {

        case Basic: {
            this->_renderBasic(screenView, uiRenderContext, uiScreenSize);
            break;
        }

        case ModsInfo: {
            this->_renderModInfo(screenView, uiRenderContext, uiScreenSize);
            break;
        }

        case DimensionInfo: {
            this->_renderDimensionInfo(screenView, uiRenderContext, uiScreenSize);
            break;
        }
    }
}

void F3Renderer::onRender() {
    if (this->mFpsHandler == nullptr)
    {
        this->mFpsHandler = new PerTickHandler();
        this->mFpsHandler->start();
    }
    this->mFpsHandler->update();
}

void F3Renderer::onTick() {
    if (this->mTpsHandler == nullptr)
    {
        this->mTpsHandler = new PerTickHandler();
        this->mTpsHandler->start();
    }
    this->mTpsHandler->update();
}

void F3Renderer::onUpdate() {
    if (this->mUpsHandler == nullptr)
    {
        this->mUpsHandler = new PerTickHandler();
        this->mUpsHandler->start();
    }
    this->mUpsHandler->update();
}

void F3Renderer::_renderBasic(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, Vec2 uiScreenSize) {
    ClientInstance* clientInstance = uiRenderContext->mClient;

    TextVectorRenderer::TextVectorTopLeftRenderer(screenView, uiRenderContext, F3DataBuilder::BuildInfoData(clientInstance, this->mAmethystContext, this->mFpsHandler, this->mTpsHandler, this->mUpsHandler), uiScreenSize);
    TextVectorRenderer::TextVectorTopRightRenderer(screenView, uiRenderContext, F3DataBuilder::BuildControlData(clientInstance), uiScreenSize);

    TextVectorRenderer::TextVectorBottomLeftRenderer(screenView, uiRenderContext, {}, uiScreenSize);
    TextVectorRenderer::TextVectorBottomRightRenderer(screenView, uiRenderContext, {}, uiScreenSize);
}

void F3Renderer::_renderModInfo(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, Vec2 uiScreenSize) {
    TextVectorRenderer::TextVectorTopLeftRenderer(screenView, uiRenderContext, F3DataBuilder::BuildModInfoData(this->mAmethystContext), uiScreenSize);
}

void F3Renderer::_renderDimensionInfo(ScreenView* screenView, MinecraftUIRenderContext* uiRenderContext, Vec2 uiScreenSize) {
    ClientInstance* clientInstance = uiRenderContext->mClient;

    TextVectorRenderer::TextVectorTopLeftRenderer(screenView, uiRenderContext, F3DataBuilder::BuildDimensionInfoData(clientInstance), uiScreenSize);
}
