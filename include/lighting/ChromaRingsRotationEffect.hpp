#pragma once

#include "UnityEngine/MonoBehaviour.hpp"
#include "GlobalNamespace/TrackLaneRingsRotationEffect.hpp"
#include "GlobalNamespace/TrackLaneRingsManager.hpp"
#include "GlobalNamespace/BeatmapEventType.hpp"
#include "GlobalNamespace/SimpleColorSO.hpp"
#include "GlobalNamespace/MultipliedColorSO.hpp"
#include "GlobalNamespace/TrackLaneRingsManager.hpp"
#include "GlobalNamespace/TrackLaneRing.hpp"
#include <vector>
#include <string>
#include <optional>
#include "custom-types/shared/types.hpp"
#include "custom-types/shared/macros.hpp"
#include "main.hpp"

DECLARE_CLASS_CODEGEN(Chroma, ChromaRotationEffect, Il2CppObject,
public:
        DECLARE_INSTANCE_FIELD(float, RotationAngle);

        DECLARE_INSTANCE_FIELD(float, RotationStep);

        DECLARE_INSTANCE_FIELD(float, RotationFlexySpeed);

        DECLARE_INSTANCE_FIELD(float, RotationPropagationSpeed);

        DECLARE_INSTANCE_FIELD(float, ProgressPos);
)

DECLARE_CLASS_CODEGEN(Chroma, ChromaRingsRotationEffect, GlobalNamespace::TrackLaneRingsRotationEffect,
public:
        std::vector<ChromaRotationEffect*> _activeRingRotationEffects;
        std::vector<ChromaRotationEffect*> _ringRotationEffectsPool;

        DECLARE_DEFAULT_CTOR();
        DECLARE_SIMPLE_DTOR();
        DECLARE_INSTANCE_METHOD(void, CopyValues, GlobalNamespace::TrackLaneRingsRotationEffect* trackLaneRingsRotationEffect);

        DECLARE_INSTANCE_METHOD(float, GetFirstRingRotationAngle);
        DECLARE_INSTANCE_METHOD(float, GetFirstRingDestinationRotationAngle);

    public:
        float GetFirstRingRotationAngleCpp() {
            static auto GetRotation = FPtrWrapper<&GlobalNamespace::TrackLaneRing::GetRotation>::get();
                if (!trackLaneRingsManager->rings) {
                getLogger().warning("Rings is null why! %p ", trackLaneRingsManager);
                trackLaneRingsManager->rings = Array<GlobalNamespace::TrackLaneRing *>::New();
            }

            return GetRotation(trackLaneRingsManager->rings->get(0));
        }

        float GetFirstRingDestinationRotationAngleCpp() {
            static auto GetDestinationRotation = FPtrWrapper<&GlobalNamespace::TrackLaneRing::GetDestinationRotation>::get();

            if (!trackLaneRingsManager->rings) {
                getLogger().warning("Rings is null why! %p ", trackLaneRingsManager);
                trackLaneRingsManager->rings = Array<GlobalNamespace::TrackLaneRing *>::New();
            }

            return GetDestinationRotation(trackLaneRingsManager->rings->get(0));
        }

        DECLARE_INSTANCE_METHOD(void, AddRingRotationEffectF, float angle, float step, float propagationSpeed, float flexySpeed);
        DECLARE_INSTANCE_METHOD(void, AddRingRotationEffect, float angle, float step, int propagationSpeed, float flexySpeed);

        DECLARE_INSTANCE_METHOD(void, SetNewRingManager, GlobalNamespace::TrackLaneRingsManager* trackLaneRingsManager);

        DECLARE_INSTANCE_METHOD(void, Awake);
        DECLARE_INSTANCE_METHOD(void, Start);
        DECLARE_INSTANCE_METHOD(void, FixedUpdate);

        DECLARE_INSTANCE_METHOD(ChromaRotationEffect*, SpawnRingRotationEffect);
        DECLARE_INSTANCE_METHOD(void, RecycleRingRotationEffect, ChromaRotationEffect* ringRotationEffect);
)