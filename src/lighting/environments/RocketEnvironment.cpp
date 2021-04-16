#include "lighting/environments/RocketEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT RocketEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
            {
                    {0, {
                                {1, 7},
                                {2, 16},
                                {3, 8},
                                {4, 5},
                                {5, 17},
                                {6, 15},
                                {7, 14},
                                {8, 12},
                                {9, 9},
                                {10, 6},
                                {11, 13},
                                {12, 11},
                                {13, 10},
                        }},
                    {1, {
                                {1, 4},
                                {2, 7},
                                {3, 8},
                                {4, 3},
                        }},
                    {2, {
                                {1, 5},
                                {2, 1},
                                {3, 3},
                                {4, 2},
                                {5, 7},
                                {6, 6},
                                {7, 4},
                        }},
                    {3, {
                                {1, 5},
                                {2, 2},
                                {3, 3},
                                {4, 1},
                                {5, 7},
                                {6, 6},
                                {7, 4},
                        }},
                    {4, {
                                {1, 9},
                                {2, 13},
                                {3, 16},
                                {4, 4},
                                {5, 2},
                                {6, 5},
                                {7, 7},
                        }},
            }
    );

}