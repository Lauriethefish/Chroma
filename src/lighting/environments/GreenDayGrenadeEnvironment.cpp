

#include "lighting/environments/GreenDayGrenadeEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT GreenDayGrenadeEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
        {
    {0, {
        {1, 10 },
        {2, 11 },
        {3, 6 },
        {4, 20 },
        {5, 16 },
        {6, 18 },
        {7, 17 },
        {8, 8 },
        {9, 21 },
        {10, 15 },
        {11, 13 },
        {12, 9 },
        {13, 19 },
        {14, 12 },
        {15, 7 },
        {16, 14 },
    }},
    {1, {
    }},
    {2, {
        {1, 5 },
        {2, 3 },
        {3, 4 },
        {4, 7 },
        {5, 1 },
        {6, 6 },
    }},
    {3, {
        {1, 6 },
        {2, 1 },
        {3, 7 },
        {4, 4 },
        {5, 3 },
        {6, 5 },
    }},
    {4, {
        {1, 6 },
        {2, 12 },
        {3, 13 },
        {4, 5 },
        {5, 8 },
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

ChromaInstallEnvironment(GreenDayGrenadeEnvironment)
