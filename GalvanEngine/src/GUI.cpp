#include "GUI.h"
#include "Window.h"

void
GUI::init() {
    // Setup GUI Style
    setupGUIStyle();
}

void
GUI::update() {
}

void
GUI::render() {
}

void
GUI::destroy() {
}

void
GUI::setupGUIStyle() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Configuración general de estilo
    style.WindowRounding = 0.0f;
    style.FrameRounding = 0.0f;
    style.PopupRounding = 0.0f;
    style.ScrollbarRounding = 0.0f;
    style.GrabRounding = 0.0f;
    style.TabRounding = 0.0f;
    style.ChildRounding = 0.0f;
    style.FrameBorderSize = 1.0f;
    style.WindowBorderSize = 1.0f;
    style.PopupBorderSize = 1.0f;
    style.TabBorderSize = 1.0f;

    // Definición de colores
    ImVec4 white = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    ImVec4 black = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 red = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 blue = ImVec4(0.0f, 0.5f, 1.0f, 1.0f);
    ImVec4 lime = ImVec4(0.5f, 1.0f, 0.0f, 1.0f);
    ImVec4 yellow = ImVec4(1.0f, 1.0f, 0.0f, 1.0f);

    // Fondo de la ventana y elementos
    colors[ImGuiCol_WindowBg] = white;
    colors[ImGuiCol_ChildBg] = white;
    colors[ImGuiCol_PopupBg] = white;

    // Texto y bordes
    colors[ImGuiCol_Text] = black;
    colors[ImGuiCol_Border] = black;
    colors[ImGuiCol_BorderShadow] = black;

    // Botones
    colors[ImGuiCol_Button] = red;
    colors[ImGuiCol_ButtonHovered] = blue;
    colors[ImGuiCol_ButtonActive] = lime;

    // Marcos y campos de entrada
    colors[ImGuiCol_FrameBg] = white;
    colors[ImGuiCol_FrameBgHovered] = yellow;
    colors[ImGuiCol_FrameBgActive] = yellow;

    // Títulos y encabezados
    colors[ImGuiCol_TitleBg] = white;
    colors[ImGuiCol_TitleBgActive] = white;
    colors[ImGuiCol_TitleBgCollapsed] = white;

    colors[ImGuiCol_Header] = red;
    colors[ImGuiCol_HeaderHovered] = blue;
    colors[ImGuiCol_HeaderActive] = lime;

    // Tabs
    colors[ImGuiCol_Tab] = red;
    colors[ImGuiCol_TabHovered] = blue;
    colors[ImGuiCol_TabActive] = lime;
    colors[ImGuiCol_TabUnfocused] = red;
    colors[ImGuiCol_TabUnfocusedActive] = lime;

    // Scrollbar
    colors[ImGuiCol_ScrollbarBg] = white;
    colors[ImGuiCol_ScrollbarGrab] = black;
    colors[ImGuiCol_ScrollbarGrabHovered] = black;
    colors[ImGuiCol_ScrollbarGrabActive] = black;

    // Sliders
    colors[ImGuiCol_SliderGrab] = black;
    colors[ImGuiCol_SliderGrabActive] = black;

    // Checkbox y radio button
    colors[ImGuiCol_CheckMark] = black;

    // Separadores y líneas
    colors[ImGuiCol_Separator] = black;
    colors[ImGuiCol_SeparatorHovered] = black;
    colors[ImGuiCol_SeparatorActive] = black;

    // Menú
    colors[ImGuiCol_MenuBarBg] = white;

    // Tooltip
    colors[ImGuiCol_TextSelectedBg] = blue;
    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.2f, 0.2f, 0.2f, 0.5f);

    // Ajustes de alineación y espaciado
    style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
    style.ItemSpacing = ImVec2(8, 4);
    style.ItemInnerSpacing = ImVec2(4, 4);
    style.FramePadding = ImVec2(4, 2);
}
