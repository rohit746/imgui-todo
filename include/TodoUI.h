#pragma once

#include "TodoManager.h"
#include "imgui.h"
#include <string>

class TodoUI
{
private:
    TodoManager &manager;
    char inputBuffer[256];
    int selectedPriority;
    int filterMode; // 0 = all, 1 = active, 2 = completed

    void renderHeader(float windowWidth, bool isNarrow);
    void renderFilterButtons(bool isNarrow);
    void renderTodoList(bool isSmall);
    void renderInputSection(float windowWidth, bool isNarrow, bool isSmall);

public:
    TodoUI(TodoManager &mgr);
    void render(const ImGuiIO &io);
};
