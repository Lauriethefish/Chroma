#include "lighting/environments/CrabRaveEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT CrabRaveEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
            {
                    {0, {
                                {1, 3},
                                {2, 5},
                                {3, 11},
                                {4, 9},
                                {5, 12},
                                {6, 8},
                                {7, 10},
                                {8, 4},
                        }},
                    {1, {
                                {1, 3},
                                {2, 11},
                                {3, 8},
                                {4, 10},
                                {5, 6},
                                {6, 4},
                                {7, 9},
                        }},
                    {2, {
                                {1, 3},
                                {2, 1},
                                {3, 2},
                                {4, 4},
                                {5, 5},
                        }},
                    {3, {
                                {1, 5},
                                {2, 4},
                                {3, 2},
                                {4, 1},
                                {5, 3},
                        }},
                    {4, {
                                {1, 16},
                                {2, 18},
                                {3, 10},
                                {4, 9},
                                {5, 1},
                                {6, 11},
                                {7, 7},
                                {8, 0},
                                {9, 13},
                                {10, 19},
                                {11, 20},
                                {12, 17},
                                {13, 6},
                                {14, 4},
                        }},
            }
    );

}