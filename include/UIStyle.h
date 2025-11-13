#pragma once

#include "imgui.h"

class UIStyle
{
public:
    static void setupCustomStyle();
    static ImU32 getPriorityColor(int priority);

    // UI Constants
    static constexpr float NARROW_WIDTH_THRESHOLD = 600.0f;
    static constexpr float SMALL_WIDTH_THRESHOLD = 800.0f;
};
