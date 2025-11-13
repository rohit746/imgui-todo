#include "TodoUI.h"
#include "UIStyle.h"
#include <cstring>

TodoUI::TodoUI(TodoManager &mgr)
    : manager(mgr), selectedPriority(1), filterMode(0)
{
    inputBuffer[0] = '\0';
}

void TodoUI::renderHeader(float windowWidth, bool isNarrow)
{
    ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 10);

    ImGui::Text("My Todo List");

    // Stats
    int active = manager.getActiveCount();
    int completed = manager.getCompletedCount();

    char statsText[64];
    snprintf(statsText, sizeof(statsText), "%d Active | %d Completed", active, completed);
    float statsWidth = ImGui::CalcTextSize(statsText).x;

    if (!isNarrow)
    {
        ImGui::SameLine();
        ImGui::SetCursorPosX(windowWidth - statsWidth - 30);
    }
    ImGui::TextColored(ImVec4(0.6f, 0.6f, 0.6f, 1.0f), "%s", statsText);

    ImGui::Separator();
    ImGui::Spacing();
}

void TodoUI::renderFilterButtons(bool isNarrow)
{
    ImGui::Text("Filter:");
    if (!isNarrow)
    {
        ImGui::SameLine();
    }

    if (ImGui::RadioButton("All", filterMode == 0))
        filterMode = 0;
    ImGui::SameLine();
    if (ImGui::RadioButton("Active", filterMode == 1))
        filterMode = 1;
    ImGui::SameLine();
    if (ImGui::RadioButton("Completed", filterMode == 2))
        filterMode = 2;

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
}

void TodoUI::renderTodoList(bool isSmall)
{
    std::vector<int> itemsToDelete;
    auto &todos = manager.getTodos();

    for (size_t i = 0; i < todos.size(); i++)
    {
        TodoItem &todo = todos[i];

        // Apply filter
        if (filterMode == 1 && todo.completed)
            continue;
        if (filterMode == 2 && !todo.completed)
            continue;

        ImGui::PushID(i);

        // Priority indicator
        ImVec2 cursorPos = ImGui::GetCursorScreenPos();
        ImDrawList *drawList = ImGui::GetWindowDrawList();
        ImU32 priorityColor = UIStyle::getPriorityColor(todo.priority);

        drawList->AddRectFilled(
            ImVec2(cursorPos.x, cursorPos.y),
            ImVec2(cursorPos.x + 4, cursorPos.y + 40),
            priorityColor,
            2.0f);

        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 12);

        // Checkbox
        bool completed = todo.completed;
        if (ImGui::Checkbox("##check", &completed))
        {
            todo.completed = completed;
        }

        ImGui::SameLine();

        // Task text
        if (todo.completed)
        {
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.5f, 0.5f, 0.5f, 1.0f));
            ImGui::Text("[DONE] %s", todo.text.c_str());
            ImGui::PopStyleColor();
        }
        else
        {
            ImGui::Text("%s", todo.text.c_str());
        }

        // Delete button
        float childWidth = ImGui::GetWindowWidth();
        float deleteBtnWidth = isSmall ? 60 : 80;

        ImGui::SameLine(childWidth - deleteBtnWidth - 10);
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.8f, 0.2f, 0.2f, 0.6f));
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.9f, 0.2f, 0.2f, 0.8f));
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(1.0f, 0.2f, 0.2f, 1.0f));

        if (ImGui::Button(isSmall ? "Del" : "Delete", ImVec2(deleteBtnWidth - 5, 0)))
        {
            itemsToDelete.push_back(i);
        }

        ImGui::PopStyleColor(3);
        ImGui::PopID();
        ImGui::Spacing();
    }

    // Delete items in reverse order
    for (auto it = itemsToDelete.rbegin(); it != itemsToDelete.rend(); ++it)
    {
        manager.deleteTodo(*it);
    }
}

void TodoUI::renderInputSection(float windowWidth, bool isNarrow, bool isSmall)
{
    ImGui::Text("Add New Task:");
    ImGui::Spacing();

    // Calculate widths
    float priorityWidth = isSmall ? 90 : 120;
    float addBtnWidth = isSmall ? 70 : 90;
    float spacing = ImGui::GetStyle().ItemSpacing.x;
    float inputWidth = isNarrow ? -10 : windowWidth - priorityWidth - addBtnWidth - spacing * 4 - 60;

    ImGui::SetNextItemWidth(inputWidth);
    bool enterPressed = ImGui::InputTextWithHint(
        "##input",
        "What needs to be done?",
        inputBuffer,
        sizeof(inputBuffer),
        ImGuiInputTextFlags_EnterReturnsTrue);

    if (isNarrow)
    {
        ImGui::Spacing();
    }
    else
    {
        ImGui::SameLine();
    }

    // Priority selector
    ImGui::SetNextItemWidth(priorityWidth);
    const char *priorities[] = {"Low", "Medium", "High"};
    ImGui::Combo("##priority", &selectedPriority, priorities, 3);

    ImGui::SameLine();

    // Add button
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.42f, 0.75f, 0.53f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.52f, 0.85f, 0.63f, 1.0f));
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.32f, 0.65f, 0.43f, 1.0f));

    bool addClicked = ImGui::Button(isSmall ? "Add" : "Add Task", ImVec2(addBtnWidth, 0));

    ImGui::PopStyleColor(3);

    // Add new todo
    if ((enterPressed || addClicked) && strlen(inputBuffer) > 0)
    {
        manager.addTodo(inputBuffer, selectedPriority);
        inputBuffer[0] = '\0';
    }

    ImGui::Spacing();

    // Clear completed button
    if (manager.getCompletedCount() > 0)
    {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.6f, 0.3f, 0.3f, 0.6f));
        const char *clearText = isSmall ? "Clear Done" : "Clear Completed Tasks";
        if (ImGui::Button(clearText))
        {
            manager.clearCompleted();
        }
        ImGui::PopStyleColor();
    }
}

void TodoUI::render(const ImGuiIO &io)
{
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Todo List", nullptr,
                 ImGuiWindowFlags_NoTitleBar |
                     ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove |
                     ImGuiWindowFlags_NoCollapse);

    float windowWidth = ImGui::GetWindowWidth();
    float windowHeight = ImGui::GetWindowHeight();
    bool isNarrow = windowWidth < UIStyle::NARROW_WIDTH_THRESHOLD;
    bool isSmall = windowWidth < UIStyle::SMALL_WIDTH_THRESHOLD;

    ImGui::PushFont(io.Fonts->Fonts[0]);

    renderHeader(windowWidth, isNarrow);
    renderFilterButtons(isNarrow);

    // Todo list items
    float bottomSectionHeight = isNarrow ? 180 : (isSmall ? 150 : 130);
    ImGui::BeginChild("TodoItems", ImVec2(0, -bottomSectionHeight), true, ImGuiWindowFlags_AlwaysVerticalScrollbar);
    renderTodoList(isSmall);
    ImGui::EndChild();

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    renderInputSection(windowWidth, isNarrow, isSmall);

    ImGui::PopFont();
    ImGui::End();
}
