//
// Created by adria on 12/02/2024.
//

#include "F3DataBuilder.h"

std::vector<std::string> F3DataBuilder::BuildInfoData(ClientInstance *clientInstance, AmethystContext* amethystContext, FpsHandler* fpsHandler, TpsHandler* tpsHandler, UpsHandler* upsHandler) {
    std::vector<std::string> data;

    Vec3* playerPos = clientInstance->getLocalPlayer()->getPosition();
    Vec2 clientUIScreenSize = clientInstance->guiData->clientUIScreenSize;
    Vec2 clientScreenSize = clientInstance->guiData->clientScreenSize;
    Vec2 totalScreenSize = clientInstance->guiData->totalScreenSize;

    auto* component = clientInstance->getLocalPlayer()->tryGetComponent<ActorRotationComponent>();
    Vec2 headRot = component->mHeadRot;

    float cardinalRot = headRot.y + 180.0f;
    std::string direction;

    if (cardinalRot >= 315.0f || cardinalRot < 45.0f) direction = "North (Towards -Z)";
    else if (cardinalRot >= 45.0f && cardinalRot < 135.0f) direction = "East (Towards +X)";
    else if (cardinalRot >= 135.0f && cardinalRot < 225.0f) direction = "South (Towards +Z)";
    else direction = "West (Towards -X)";

    data.emplace_back(fmt::format("Minecraft Version: {}",amethystContext->mMinecraftPackageInfo.mVersion.mFullVersionString));
    data.emplace_back(fmt::format("Amethyst Version: {}", "1.2.1"));
    data.emplace_back("");
    data.emplace_back(fmt::format("TPS: {:.2f}", fpsHandler->mFps));
    data.emplace_back(fmt::format("FPS: {:.2f}", tpsHandler->mTps));
    data.emplace_back(fmt::format("UPS: {:.2f}", upsHandler->mUps));
    data.emplace_back("");
    data.emplace_back(fmt::format("Position: [ x: {:.2f}, y: {:.2f}, z: {:.2f} ]", playerPos->x, playerPos->y, playerPos->z));
    data.emplace_back(fmt::format("Biome: Savanna"));
    data.emplace_back("");
    data.emplace_back(fmt::format("Rotation: [ x: {:.2f}, y: {:.2f} ]", headRot.x, headRot.y));
    data.emplace_back(fmt::format("Facing: {}", direction));
    data.emplace_back("");
    data.emplace_back(fmt::format("Client UI Screen Size: [ x: {}, y: {} ]", clientUIScreenSize.x, clientUIScreenSize.y));
    data.emplace_back(fmt::format("Client Screen Size: [ x: {}, y: {} ]", clientScreenSize.x, clientScreenSize.y));
    data.emplace_back(fmt::format("Total Screen Size: [ x: {}, y: {} ]", totalScreenSize.x, totalScreenSize.y));

    return data;
}

std::vector<std::string> F3DataBuilder::BuildControlData(ClientInstance *clientInstance) {
    std::vector<std::string> data;

    data.emplace_back("Graph: F3 + g");
    data.emplace_back("Chunk Borders: F3 + g");
    data.emplace_back("Current Block: F3 + y");
    data.emplace_back("Current Entity: F3 + x");
    data.emplace_back("Other: F3 + y");

    return data;
}
