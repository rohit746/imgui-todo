#include "UIStyle.h"

void UIStyle::setupCustomStyle()
{
    ImGuiStyle &style = ImGui::GetStyle();

    style.WindowRounding = 12.0f;
    style.FrameRounding = 8.0f;
    style.ScrollbarRounding = 12.0f;
    style.GrabRounding = 8.0f;
    style.PopupRounding = 8.0f;
    style.FramePadding = ImVec2(10, 8);
    style.ItemSpacing = ImVec2(10, 8);
    style.WindowPadding = ImVec2(15, 15);

    ImVec4 *colors = style.Colors;
    colors[ImGuiCol_WindowBg] = ImVec4(0.13f, 0.14f, 0.17f, 1.00f);
    colors[ImGuiCol_ChildBg] = ImVec4(0.16f, 0.17f, 0.21f, 1.00f);
    colors[ImGuiCol_PopupBg] = ImVec4(0.16f, 0.17f, 0.21f, 1.00f);
    colors[ImGuiCol_Border] = ImVec4(0.26f, 0.27f, 0.31f, 1.00f);
    colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.21f, 0.25f, 1.00f);
    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.25f, 0.29f, 1.00f);
    colors[ImGuiCol_FrameBgActive] = ImVec4(0.28f, 0.29f, 0.33f, 1.00f);
    colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.11f, 0.14f, 1.00f);
    colors[ImGuiCol_TitleBgActive] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
    colors[ImGuiCol_MenuBarBg] = ImVec4(0.16f, 0.17f, 0.21f, 1.00f);
    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.11f, 0.14f, 1.00f);
    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.30f, 0.31f, 0.35f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.41f, 0.45f, 1.00f);
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.50f, 0.51f, 0.55f, 1.00f);
    colors[ImGuiCol_CheckMark] = ImVec4(0.42f, 0.75f, 0.53f, 1.00f);
    colors[ImGuiCol_SliderGrab] = ImVec4(0.42f, 0.75f, 0.53f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.52f, 0.85f, 0.63f, 1.00f);
    colors[ImGuiCol_Button] = ImVec4(0.42f, 0.75f, 0.53f, 0.80f);
    colors[ImGuiCol_ButtonHovered] = ImVec4(0.42f, 0.75f, 0.53f, 1.00f);
    colors[ImGuiCol_ButtonActive] = ImVec4(0.52f, 0.85f, 0.63f, 1.00f);
    colors[ImGuiCol_Header] = ImVec4(0.42f, 0.75f, 0.53f, 0.55f);
    colors[ImGuiCol_HeaderHovered] = ImVec4(0.42f, 0.75f, 0.53f, 0.80f);
    colors[ImGuiCol_HeaderActive] = ImVec4(0.42f, 0.75f, 0.53f, 1.00f);
    colors[ImGuiCol_Separator] = ImVec4(0.26f, 0.27f, 0.31f, 1.00f);
    colors[ImGuiCol_TextSelectedBg] = ImVec4(0.42f, 0.75f, 0.53f, 0.35f);
}

ImU32 UIStyle::getPriorityColor(int priority)
{
    switch (priority)
    {
    case 2:
        return IM_COL32(231, 76, 60, 255); // Red for high
    case 1:
        return IM_COL32(241, 196, 15, 255); // Yellow for medium
    default:
        return IM_COL32(52, 152, 219, 255); // Blue for low
    }
}
