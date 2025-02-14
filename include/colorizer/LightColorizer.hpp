#pragma once

#include "main.hpp"
#include "Chroma.hpp"
#include "sombrero/shared/ColorUtils.hpp"

#include "custom-types/shared/types.hpp"
#include "custom-types/shared/macros.hpp"

#include "GlobalNamespace/ILightWithId.hpp"
#include "GlobalNamespace/LightSwitchEventEffect.hpp"
#include "GlobalNamespace/BeatmapEventType.hpp"
#include "GlobalNamespace/SimpleColorSO.hpp"
#include "GlobalNamespace/MultipliedColorSO.hpp"
#include "GlobalNamespace/LightWithIdManager.hpp"

#include "UnityEngine/MonoBehaviour.hpp"

#include <vector>
#include <string>
#include <optional>

namespace Chroma {
    class LightColorizer {
    private:
        static const int COLOR_FIELDS = 4;

        GlobalNamespace::LightSwitchEventEffect *_lightSwitchEventEffect;
        GlobalNamespace::BeatmapEventType _eventType;
        std::unordered_map<int, std::optional<Sombrero::FastColor>> _colors;

        std::vector<Sombrero::FastColor> _originalColors;
        std::unordered_map<int, SafePtr<GlobalNamespace::SimpleColorSO>> _simpleColorSOs;

        LightColorizer(GlobalNamespace::LightSwitchEventEffect *lightSwitchEventEffect,
                       GlobalNamespace::BeatmapEventType beatmapEventType);

    public:
        static std::shared_ptr<LightColorizer> New(GlobalNamespace::LightSwitchEventEffect *lightSwitchEventEffect,
                                                   GlobalNamespace::BeatmapEventType beatmapEventType);

        inline static std::vector<std::optional<Sombrero::FastColor>> GlobalColor{std::nullopt, std::nullopt,
                                                                                  std::nullopt, std::nullopt};

        inline static UnorderedEventCallback<GlobalNamespace::BeatmapEventType, std::vector<Sombrero::FastColor>> LightColorChanged;

        inline static std::unordered_map<int, std::shared_ptr<LightColorizer>> Colorizers;

        std::vector<GlobalNamespace::ILightWithId *> Lights{};

        std::unordered_map<int, std::vector<GlobalNamespace::ILightWithId *>> LightsPropagationGrouped{};


        std::vector<Sombrero::FastColor> getColor() {
            std::vector<Sombrero::FastColor> colors(COLOR_FIELDS);
#pragma unroll
            for (int i = 0; i < COLOR_FIELDS; i++) {
                auto &color = _colors[i];

                if (!color)
                    color = GlobalColor[i];

                if (!color)
                    color = _originalColors[i];


                colors[i] = *color;
            }

            return colors;
        }

        static void GlobalColorize(bool refresh, std::vector<std::optional<Sombrero::FastColor>> const &colors);

        static void RegisterLight(UnityEngine::MonoBehaviour *lightWithId, std::optional<int> lightId);

        void Colorize(bool refresh, std::vector<std::optional<Sombrero::FastColor>> const &colors) {
            for (int i = 0; i < colors.size(); i++) {
                _colors[i] = colors[i];
            }

            // Allow light colorizer to not force color
            if (refresh) {
                Refresh();
            } else {
                SetSOs(getColor());
            }
        }

        static void Reset();

        // extensions
        inline static std::shared_ptr<LightColorizer>
        GetLightColorizer(GlobalNamespace::BeatmapEventType beatmapEventType) {
            auto it = Colorizers.find(beatmapEventType.value);
            if (it == Colorizers.end()) {
                return nullptr;
            }

            return it->second;
        }

        inline static void ColorizeLight(GlobalNamespace::BeatmapEventType beatmapEventType, bool refresh,
                                         std::vector<std::optional<Sombrero::FastColor>> const &colors) {
            CRASH_UNLESS(GetLightColorizer(beatmapEventType))->Colorize(refresh, colors);
        }

    private:
        void SetSOs(std::vector<Sombrero::FastColor> const &colors) {
            static auto SetColor = FPtrWrapper<&GlobalNamespace::SimpleColorSO::SetColor>::get();

            for (int i = 0; i < colors.size(); i++) {
                SetColor((GlobalNamespace::SimpleColorSO *) _simpleColorSOs[i], colors[i]);
            }

            LightColorChanged.invoke(_eventType.value, colors);
        }

        void Refresh() {
            auto const &colors = getColor();
            SetSOs(colors);

            static auto ProcessLightSwitchEvent = FPtrWrapper<&GlobalNamespace::LightSwitchEventEffect::ProcessLightSwitchEvent>::get();
            ProcessLightSwitchEvent(_lightSwitchEventEffect,
                                    _lightSwitchEventEffect->prevLightSwitchBeatmapEventDataValue, true);
        }

        void InitializeSO(std::string_view id, int index);
    };
}



