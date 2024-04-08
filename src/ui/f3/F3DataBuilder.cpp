//
// Created by adria on 12/02/2024.
//

#include "F3DataBuilder.h"

std::vector<std::string> F3DataBuilder::BuildInfoData(ClientInstance *clientInstance, AmethystContext* amethystContext, PerTickHandler* fpsHandler, PerTickHandler* tpsHandler, PerTickHandler* upsHandler) {
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
    data.emplace_back(fmt::format("TPS: {:.2f}", fpsHandler->mPT));
    data.emplace_back(fmt::format("FPS: {:.2f}", tpsHandler->mPT));
    data.emplace_back(fmt::format("UPS: {:.2f}", upsHandler->mPT));
    data.emplace_back("");
    data.emplace_back(fmt::format("Position: [ X: {:.2f}, Y: {:.2f}, Z: {:.2f} ]", playerPos->x, playerPos->y, playerPos->z));
    data.emplace_back(fmt::format("Biome: Savanna"));
    data.emplace_back("");
    data.emplace_back(fmt::format("Rotation: [ X: {:.2f}, Y: {:.2f} ]", headRot.x, headRot.y));
    data.emplace_back(fmt::format("Facing: {}", direction));
    data.emplace_back("");
    data.emplace_back(fmt::format("Client UI Screen Size: [ X: {}, Y: {} ]", clientUIScreenSize.x, clientUIScreenSize.y));
    data.emplace_back(fmt::format("Client Screen Size: [ X: {}, Y: {} ]", clientScreenSize.x, clientScreenSize.y));
    data.emplace_back(fmt::format("Total Screen Size: [ X: {}, Y: {} ]", totalScreenSize.x, totalScreenSize.y));

    return data;
}

std::vector<std::string> F3DataBuilder::BuildControlData(ClientInstance *clientInstance) {
    std::vector<std::string> data;

    data.emplace_back("Graph: F3 + G");
    data.emplace_back("Chunk Borders: F3 + G");
    data.emplace_back("Current Block: F3 + Y");
    data.emplace_back("Current Entity: F3 + X");
    data.emplace_back("Other: F3 + Y");

    return data;
}

std::vector<std::string> F3DataBuilder::BuildModInfoData(AmethystContext *amethystContext) {
    std::vector<std::string> data;

    for (int mod_i = 0; mod_i < amethystContext->mMods.size(); ++mod_i)
    {
        auto mod = amethystContext->mMods.at(mod_i);

        data.emplace_back(fmt::format("{}:", mod.modName));
        data.emplace_back(fmt::format("  Name: {}", mod.metadata.name));
        data.emplace_back(fmt::format("  Version: {}", mod.metadata.version));
        data.emplace_back("  Author:");

        for (int author_i = 0; author_i < mod.metadata.author.size(); ++author_i) {
            auto author = mod.metadata.author.at(author_i);

            if (author_i != mod.metadata.author.size() - 1) {
                data.emplace_back(fmt::format("    {},", author));
            } else {
                data.emplace_back(fmt::format("    {}", author));
            }
        }

        if (mod_i != amethystContext->mMods.size() - 1) {
            data.emplace_back("");
        }
    }

    return data;
}

std::vector<std::string> F3DataBuilder::BuildDimensionInfoData(ClientInstance* clientInstance) {
    std::vector<std::string> data;

    Dimension dim = clientInstance->getRegion()->getDimensionConst();

    data.emplace_back("Dimension:");

    data.emplace_back(fmt::format("  Name: {}", dim.mName));
    data.emplace_back(fmt::format("  ID: {}", dim.mId));
    data.emplace_back(fmt::format("  Min-Y: {}", dim.mHeightRange.mMinHeight));
    data.emplace_back(fmt::format("  Max-Y: {}", dim.mHeightRange.mMaxHeight));
    data.emplace_back(fmt::format("  SeaLevel: {}", dim.mSeaLevel));
    data.emplace_back(fmt::format("  Ultra Warm: {}", dim.mUltraWarm));
    data.emplace_back(fmt::format("  Has Ceiling: {}", dim.mHasCeiling));
    data.emplace_back(fmt::format("  Has Weather: {}", dim.mHasWeather));
    data.emplace_back(fmt::format("  Has Skylight: {}", dim.mHasSkylight));


    return data;
}
