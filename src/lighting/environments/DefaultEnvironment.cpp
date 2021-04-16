#include "lighting/environments/DefaultEnvironment.hpp"

using namespace Chroma;

EnvironmentLightDataT DefaultEnvironment::getEnvironmentLights() {
    return EnvironmentLightDataT(
            {
                    {0, {
                                {1, 8},
                                {2, 9},
                                {3, 12},
                                {4, 10},
                                {5, 13},
                                {6, 11},
                                {7, 6},
                                {8, 5},
                                {9, 7},
                                {10, 14},
                        }},
                    {1, {
                                {1, 5},
                                {2, 6},
                                {3, 7},
                                {4, 8},
                                {5, 9},
                                {6, 10},
                                {7, 11},
                                {8, 12},
                                {9, 13},
                                {10, 14},
                                {11, 15},
                                {12, 16},
                                {13, 17},
                                {14, 18},
                                {15, 19},
                                {16, 20},
                                {17, 21},
                                {18, 22},
                                {19, 23},
                                {20, 24},
                                {21, 25},
                                {22, 26},
                                {23, 27},
                                {24, 28},
                                {25, 29},
                                {26, 30},
                                {27, 31},
                                {28, 32},
                                {29, 33},
                                {30, 34},
                                {31, 35},
                                {32, 36},
                                {33, 37},
                                {34, 38},
                                {35, 39},
                                {36, 40},
                                {37, 41},
                                {38, 42},
                                {39, 43},
                                {40, 44},
                                {41, 45},
                                {42, 46},
                                {43, 47},
                                {44, 48},
                                {45, 49},
                                {46, 50},
                                {47, 51},
                                {48, 52},
                                {49, 53},
                                {50, 54},
                                {51, 55},
                                {52, 56},
                                {53, 57},
                                {54, 58},
                                {55, 59},
                                {56, 60},
                                {57, 61},
                                {58, 62},
                                {59, 63},
                                {60, 64},
                        }},
                    {2, {
                                {1, 6},
                                {2, 8},
                                {3, 7},
                                {4, 13},
                                {5, 5},
                                {6, 10},
                                {7, 0},
                                {8, 14},
                                {9, 11},
                                {10, 1},
                                {11, 15},
                        }},
                    {3, {
                                {1, 6},
                                {2, 7},
                                {3, 8},
                                {4, 13},
                                {5, 5},
                                {6, 15},
                                {7, 2},
                                {8, 9},
                                {9, 14},
                                {10, 3},
                                {11, 10},
                        }},
                    {4, {
                                {1, 6},
                                {2, 5},
                                {3, 11},
                                {4, 13},
                                {5, 9},
                                {6, 12},
                                {7, 8},
                                {8, 0},
                                {9, 7},
                                {10, 10},
                                {11, 16},
                                {12, 15},
                                {13, 18},
                                {14, 20},
                        }},
            }
    );

}