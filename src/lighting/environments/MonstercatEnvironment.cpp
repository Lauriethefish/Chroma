

#include "lighting/environments/MonstercatEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT MonstercatEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {0, {
        {1, 5 },
        {2, 9 },
        {3, 11 },
        {4, 13 },
        {5, 10 },
        {6, 8 },
        {7, 12 },
        {8, 7 },
    }},
    {1, {
        {1, 8 },
        {2, 4 },
        {3, 5 },
        {4, 10 },
        {5, 12 },
        {6, 9 },
        {7, 11 },
    }},
    {2, {
        {1, 2 },
        {2, 3 },
        {3, 4 },
        {4, 5 },
        {5, 6 },
    }},
    {3, {
        {1, 6 },
        {2, 4 },
        {3, 5 },
        {4, 2 },
        {5, 3 },
    }},
    {4, {
        {1, 17 },
        {2, 14 },
        {3, 11 },
        {4, 10 },
        {5, 1 },
        {6, 12 },
        {7, 8 },
        {8, 0 },
        {9, 20 },
        {10, 18 },
        {11, 19 },
        {12, 21 },
        {13, 6 },
        {14, 4 },
    }},
    {5, {
    }},
    {6, {
    }},
    {7, {
    }},
}
    );
}

ChromaInstallEnvironment(MonstercatEnvironment)
