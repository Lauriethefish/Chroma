#include "lighting/environments/OriginsEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT OriginsEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
            {
                    {0, {
                                {1, 1},
                                {2, 3},
                                {3, 2},
                                {4, 4},
                        }},
                    {1, {
                                {1, 3},
                                {2, 4},
                                {3, 5},
                                {4, 6},
                                {5, 7},
                                {6, 8},
                                {7, 9},
                                {8, 10},
                                {9, 11},
                                {10, 12},
                                {11, 13},
                                {12, 14},
                                {13, 15},
                                {14, 16},
                                {15, 17},
                                {16, 18},
                                {17, 19},
                                {18, 20},
                                {19, 21},
                                {20, 22},
                                {21, 23},
                                {22, 24},
                                {23, 25},
                                {24, 26},
                                {25, 27},
                                {26, 28},
                                {27, 29},
                                {28, 30},
                                {29, 31},
                                {30, 32},
                                {31, 33},
                                {32, 34},
                                {33, 35},
                                {34, 36},
                                {35, 37},
                                {36, 38},
                                {37, 39},
                                {38, 40},
                                {39, 41},
                                {40, 42},
                                {41, 43},
                                {42, 44},
                                {43, 45},
                                {44, 46},
                                {45, 47},
                                {46, 48},
                                {47, 49},
                                {48, 50},
                                {49, 51},
                                {50, 52},
                                {51, 53},
                                {52, 54},
                                {53, 55},
                                {54, 56},
                                {55, 57},
                                {56, 58},
                                {57, 59},
                                {58, 60},
                                {59, 61},
                                {60, 62},
                        }},
                    {2, {
                                {1, 2},
                                {2, 6},
                                {3, 5},
                                {4, 7},
                                {5, 4},
                                {6, 0},
                        }},
                    {3, {
                                {1, 3},
                                {2, 8},
                                {3, 6},
                                {4, 7},
                                {5, 5},
                                {6, 0},
                        }},
                    {4, {
                                {1, 4},
                                {2, 2},
                        }},
            }
    );

}