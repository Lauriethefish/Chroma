#pragma once

#include "GlobalNamespace/BeatmapEventType.hpp"
#include "GlobalNamespace/BeatmapEventData.hpp"

#include "UnityEngine/Color.hpp"

#include "sombrero/shared/ColorUtils.hpp"

#include "System/Collections/Generic/List_1.hpp"
#include "System/Collections/Generic/IReadOnlyList_1.hpp"

#include <unordered_map>
#include <vector>
#include <optional>
#include <utility>

namespace Chroma {
// Please let me delete this whole class
    class LegacyLightHelper {
    public:
        typedef std::unordered_map<int, std::vector<pair<float, Sombrero::FastColor>>> ColorMap;

        //internal
        inline const static int RGB_INT_OFFSET = 2000000000;

        // internal
        static ColorMap LegacyColorEvents;

        // internal
        static void Activate(const std::vector<GlobalNamespace::BeatmapEventData*>& eventData);

        // internal
        static std::optional<Sombrero::FastColor> GetLegacyColor(GlobalNamespace::BeatmapEventData* beatmapEventData);

    private:
        static constexpr Sombrero::FastColor ColorFromInt(int rgb);
    };
}