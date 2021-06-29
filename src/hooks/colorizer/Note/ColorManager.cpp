#include "hooks/colorizer/Note/ColorManager.hpp"
#include "Chroma.hpp"

#include "ChromaController.hpp"
#include "utils/ChromaUtils.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/BeatmapObjectSpawnController.hpp"
#include "GlobalNamespace/NoteController.hpp"
#include "GlobalNamespace/MultiplayerConnectedPlayerNoteController.hpp"
#include "GlobalNamespace/TutorialNoteController.hpp"
#include "GlobalNamespace/ColorExtensions.hpp"

#include "custom-json-data/shared/CustomBeatmapData.h"

#include "colorizer/NoteColorizer.hpp"
#include "colorizer/BombColorizer.hpp"
#include "ChromaObjectData.hpp"
#include "hooks/colorizer/Note/ColorManager.hpp"

using namespace Chroma;
using namespace GlobalNamespace;
using namespace UnityEngine;

MAKE_HOOK_OFFSETLESS(ColorManager_ColorForType, Color, ColorManager* self, GlobalNamespace::ColorType type) {
    // Do nothing if Chroma shouldn't run
    if (!ChromaController::DoChromaHooks() || !ColorManagerColorForType::_noteColorOverride) {
        return ColorManager_ColorForType(self, type);
    }

    return ColorManagerColorForType::_noteColorOverride.value();
}


void ColorManagerHook(Logger& logger) {
    INSTALL_HOOK_OFFSETLESS(logger, ColorManager_ColorForType, il2cpp_utils::FindMethodUnsafe("", "ColorManager", "ColorForType", 1));
}

ChromaInstallHooks(ColorManagerHook)