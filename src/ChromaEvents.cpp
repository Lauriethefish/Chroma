#include "ChromaEvents.hpp"

#include "Chroma.hpp"
#include "lighting/ChromaFogController.hpp"

#include "GlobalNamespace/BeatmapData.hpp"
#include "GlobalNamespace/BeatmapObjectCallbackController.hpp"

#include "custom-json-data/shared/CustomBeatmapData.h"
#include "custom-json-data/shared/CustomEventData.h"
#include "custom-types/shared/register.hpp"

#include "tracks/shared/TimeSourceHelper.h"
#include "tracks/shared/Vector.h"

using namespace GlobalNamespace;
using namespace NEVector;

void ChromaEvents::parseEventData(TracksAD::BeatmapAssociatedData &beatmapAD, const CustomJSONData::CustomEventData *customEventData) {
    if (customEventData->type != Chroma::ASSIGNFOGTRACK)
        return;

    rapidjson::Value &eventData = *customEventData->data;
    auto& eventAD = getEventAD(customEventData);

    if (eventAD.parsed)
        return;

    auto trackIt = eventData.FindMember("_track");

    if (trackIt == eventData.MemberEnd() || trackIt->value.IsNull() || !trackIt->value.IsString()) {
        eventAD.parsed = true;
        getLogger().debug("Track data is missing for Chroma custom event %f", customEventData->time);
        return;
    }

    std::string trackName(trackIt->value.GetString());
    Track *track = &beatmapAD.tracks[trackName];

    eventAD.track = track;

    if (customEventData->type == Chroma::ASSIGNFOGTRACK) {}

    eventAD.parsed = true;
}

void ChromaEvents::deserialize(GlobalNamespace::IReadonlyBeatmapData* readOnlyBeatmap) {
    auto beatmapCast = il2cpp_utils::try_cast<CustomJSONData::CustomBeatmapData>(readOnlyBeatmap);
    if (beatmapCast) {
        auto beatmap = *beatmapCast;
        auto &beatmapAD = TracksAD::getBeatmapAD(beatmap->customData);

        if (!beatmapAD.valid) {
            TracksAD::readBeatmapDataAD(beatmap);
        }

        // Parse events
        for (auto const &customEventData: *beatmap->customEventsData) {
            parseEventData(beatmapAD, &customEventData);
        }
    }
}

void CustomEventCallback(BeatmapObjectCallbackController *callbackController,
                         CustomJSONData::CustomEventData *customEventData) {
    if (customEventData->type != Chroma::ASSIGNFOGTRACK) {
        return;
    }

    auto const &ad = ChromaEvents::getEventAD(customEventData);

    // fail safe, idek why this needs to be done smh
    // CJD you bugger
    if (!ad.parsed) {
        auto *customBeatmapData = (CustomJSONData::CustomBeatmapData *)callbackController->beatmapData;
        TracksAD::BeatmapAssociatedData &beatmapAD = TracksAD::getBeatmapAD(customBeatmapData->customData);
        ChromaEvents::parseEventData(beatmapAD, customEventData);
    }

    if (customEventData->type == Chroma::ASSIGNFOGTRACK) {
        Chroma::ChromaFogController::getInstance()->AssignTrack(ad.track);
    }
}

void ChromaEvents::AddEventCallbacks(Logger &logger) {
    CustomJSONData::CustomEventCallbacks::AddCustomEventCallback(&CustomEventCallback);
}
