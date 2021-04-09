#pragma once
#include <vector>
#include <string>
#include <optional>
#include <unordered_map>

#include "custom-types/shared/types.hpp"
#include "custom-types/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
#include "UnityEngine/Color.hpp"

#include "GlobalNamespace/BeatmapEventType.hpp"

#include "utils/Easing.hpp"
#include "main.hpp"

#include "beatsaber-hook/shared/config/rapidjson-utils.hpp"

namespace Chroma {
    struct ChromaGradientEvent {
        UnityEngine::Color _initcolor;
        UnityEngine::Color _endcolor;
        float _start;
        float _duration;
        GlobalNamespace::BeatmapEventType _event;
        ChromaUtils::Functions _easing;

        ChromaGradientEvent(UnityEngine::Color initcolor, UnityEngine::Color endcolor, float start, float duration, GlobalNamespace::BeatmapEventType eventType, ChromaUtils::Functions easing = ChromaUtils::Functions::easeLinear);

        [[nodiscard]] UnityEngine::Color Interpolate() const;
    };


}

typedef std::unordered_map<int, Chroma::ChromaGradientEvent> gradientMap;

DECLARE_CLASS_CODEGEN(Chroma, ChromaGradientController, UnityEngine::MonoBehaviour,
                            private:
                                static Chroma::ChromaGradientController* _instance;
public:
                            // internal
                            gradientMap Gradients;

                                static UnityEngine::Color AddGradient(/*dynamic*/ rapidjson::Value* gradientObject, GlobalNamespace::BeatmapEventType id, float time);
                              DECLARE_METHOD(static Chroma::ChromaGradientController*, getInstance);
                              DECLARE_METHOD(static bool, IsGradientActive, GlobalNamespace::BeatmapEventType eventType);
                              DECLARE_METHOD(static void, CancelGradient, GlobalNamespace::BeatmapEventType eventType);
                              DECLARE_METHOD(void, Update);
                              DECLARE_CTOR(ctor);
                              DECLARE_SIMPLE_DTOR(ChromaGradientController);


                              REGISTER_FUNCTION(Chroma::ChromaGradientController,
                                    getLogger().debug("Registering ChromaGradientController!");
                              REGISTER_METHOD(ctor);
                              REGISTER_SIMPLE_DTOR;
                              REGISTER_METHOD(getInstance);
                              REGISTER_METHOD(IsGradientActive);
                              REGISTER_METHOD(CancelGradient);
//                              REGISTER_METHOD(AddGradient);
                              REGISTER_METHOD(Update);


                      )
)
