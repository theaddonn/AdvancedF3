#pragma once
#include "minecraft/src-client/common/client/renderer/screen/MinecraftUIRenderContext.hpp"
#include <string>
#include <vector>

namespace F3Renderer {
void RenderTopLeft(MinecraftUIRenderContext& ctx, std::vector<std::string> text);
void RenderTopRight(MinecraftUIRenderContext& ctx, std::vector<std::string> text);
void RenderBottomLeft(MinecraftUIRenderContext& ctx, std::vector<std::string> text);
void RenderBottomRight(MinecraftUIRenderContext& ctx, std::vector<std::string> text);
} // namespace F3Renderer
