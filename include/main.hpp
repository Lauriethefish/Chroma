#pragma once

#include "modloader/shared/modloader.hpp"

#include "beatsaber-hook/shared/config/rapidjson-utils.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/config/config-utils.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-functions.hpp"
#include "ChromaConfig.hpp"

#include <string>

Configuration& getConfig();
Logger& getLogger();
void setChromaEnv();

#if DEBUGB == 0
    #define debugSpamLog(context, ...) \
    context.debug(__VA_ARGS__)
#else
    #define debugSpamLog(context, ...) \
    ((void)0)
#endif

inline const std::string modName = "Chroma";

static ModInfo modInfo;