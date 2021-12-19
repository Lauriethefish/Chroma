#pragma once

#include "custom-types/shared/coroutine.hpp"
#include "GlobalNamespace/BeatmapObjectSpawnController.hpp"
#include "GlobalNamespace/IAudioTimeSource.hpp"

#include "custom-types/shared/types.hpp"
#include "custom-types/shared/macros.hpp"

#include "System/Collections/Generic/IEnumerator_1.hpp"

#include "UnityEngine/WaitForEndOfFrame.hpp"
#include "UnityEngine/SceneManagement/Scene.hpp"

#include "main.hpp"

namespace Chroma {
    typedef rapidjson::GenericDocument<rapidjson::UTF16<char16_t>> DocumentUTF16;

    class ChromaController {
    private:
        static bool ChromaLegacy;
        static bool ChromaMap;
        static std::unordered_set<std::string> ModsForcingDoHooks;

    public:
        static bool TutorialMode;
        // Return true if Chroma should color the sabers
        // Practically the same as DoChromaHooks, so yeet?
        static bool DoColorizerSabers() {
            return ChromaRequired();
        }

        // Return true if Chroma is required/suggested in a map
        static bool ChromaRequired() {
            return (!TutorialMode && ChromaMap) || ModsForcingDoHooks.size() > 0;
        }

        static void setChromaRequired(bool chromaMap);

        // Return true if Chroma hooks should run
        static bool DoChromaHooks() {
            return getChromaConfig().customColorEventsEnabled.GetValue() && (ChromaRequired());
        }

        static void AddForceDoHooks(ModInfo& modInfo);
        static void RemoveForceDoHooks(ModInfo& modInfo);

        // Quest internal stuff
        static void SetChromaLegacy(bool v);

        static bool GetChromaLegacy() {
            return ChromaLegacy;
        }

        inline static GlobalNamespace::BeatmapObjectSpawnController* BeatmapObjectSpawnController = nullptr;
        inline static GlobalNamespace::IAudioTimeSource* IAudioTimeSource = nullptr;

        // internal
        static void OnActiveSceneChanged(UnityEngine::SceneManagement::Scene current);

        static custom_types::Helpers::Coroutine DelayedStartEnumerator(GlobalNamespace::BeatmapObjectSpawnController *beatmapObjectSpawnController);

        // Since level data is freed on scene load, we copy it before we load.
        inline static std::optional<DocumentUTF16> infoDatCopy = std::nullopt;
    };
}