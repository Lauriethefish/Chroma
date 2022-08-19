#pragma once

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/MonoBehaviour.hpp"

#include "GlobalNamespace/TrackLaneRing.hpp"
#include "GlobalNamespace/ParametricBoxController.hpp"
#include "GlobalNamespace/BeatmapObjectsAvoidance.hpp"
#include "GlobalNamespace/IReadonlyBeatmapData.hpp"

#include "sombrero/shared/ColorUtils.hpp"

#include "tracks/shared/Animation/Track.h"

#include "custom-json-data/shared/JSONWrapper.h"
#include "custom-json-data/shared/CustomBeatmapData.h"

#include <vector>
#include <string>
#include <optional>
#include "custom-types/shared/types.hpp"
#include "custom-types/shared/macros.hpp"
#include "main.hpp"

namespace Chroma {
    struct GameObjectTrackControllerData {
        std::vector<Track*> const _track;

        // nullable
        GlobalNamespace::TrackLaneRing * const _trackLaneRing;
        GlobalNamespace::ParametricBoxController * const _parametricBoxController;
        GlobalNamespace::BeatmapObjectsAvoidance * const _beatmapObjectsAvoidance;

        float const _noteLinesDistance;

        bool const v2;

        GameObjectTrackControllerData(std::vector<Track*> track,
                                                GlobalNamespace::TrackLaneRing * trackLaneRing,
                                                GlobalNamespace::ParametricBoxController * parametricBoxController,
                                                GlobalNamespace::BeatmapObjectsAvoidance * beatmapObjectsAvoidance,
                                                float noteLinesDistance, bool v2) : _track(track), _trackLaneRing(trackLaneRing),
                                                                 _parametricBoxController(parametricBoxController),
                                                                 _beatmapObjectsAvoidance(beatmapObjectsAvoidance),
                                                                 _noteLinesDistance(noteLinesDistance), v2(v2) {}
    };
}


DECLARE_CLASS_CODEGEN(Chroma, GameObjectTrackController, UnityEngine::MonoBehaviour,

private:
    inline static int nextId = 0;

    // Unity doesn't like copying my data, so we store it and copy the ID.
    inline static std::unordered_map<int, GameObjectTrackControllerData> _dataMap{};

    DECLARE_INSTANCE_FIELD(int, id);
    DECLARE_INSTANCE_FIELD(UnityEngine::Transform*, parent);
    DECLARE_INSTANCE_FIELD(UnityEngine::Transform*, origin);



    // This is retrived from the data map since Unity doesn't copy it.
    GameObjectTrackControllerData const* data;
    uint64_t lastCheckedTime;

    void UpdateData(bool force);

    DECLARE_INSTANCE_METHOD(void, Awake);
    DECLARE_INSTANCE_METHOD(void, OnEnable);
    DECLARE_INSTANCE_METHOD(void, Update);
    DECLARE_INSTANCE_METHOD(void, OnTransformParentChanged);
public:
    inline static bool LeftHanded;
    void Init(std::vector<Track*> track, float noteLinesDistance, GlobalNamespace::TrackLaneRing* trackLaneRing,
                            GlobalNamespace::ParametricBoxController* parametricBoxController,
                            GlobalNamespace::BeatmapObjectsAvoidance* beatmapObjectsAvoidance, bool v2);

    static void HandleTrackData(UnityEngine::GameObject* gameObject,
                                std::vector<Track*> track,
                                float noteLinesDistance,
                                GlobalNamespace::TrackLaneRing* trackLaneRing,
                                GlobalNamespace::ParametricBoxController* parametricBoxController,
                                GlobalNamespace::BeatmapObjectsAvoidance* beatmapObjectsAvoidance, bool v2);

    static void ClearData();

    DECLARE_SIMPLE_DTOR();
    DECLARE_DEFAULT_CTOR();
)
