#include "GUI.h"
#include "Window.h"
#include "ECS/Actor.h"

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

void GUI::Outliner(std::vector<EngineUtilities::TSharedPointer<Actor>> actors)
{
    ImGui::Begin("Outliner");

    // Iterate over the actors
    for (size_t i = 0; i < actors.size(); ++i)
    {
        auto& actor = actors[i];
        if (actor.isNull())
            continue;

        // Set node flags
        ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;

        // Highlight the selected actor
        if (actor == m_actors)
            node_flags |= ImGuiTreeNodeFlags_Selected;

        // Create a tree node for the actor
        bool node_open = ImGui::TreeNodeEx((void*)(intptr_t)i, node_flags, actor->getName().c_str());

        // Handle selection
        if (ImGui::IsItemClicked())
        {
            m_actors = actor;
            // You can perform additional actions when an actor is selected
        }

        // If the node is open, display its components
        if (node_open)
        {
            // Display components
            const auto& components = actor->getComponents();
            for (size_t j = 0; j < components.size(); ++j)
            {
                auto& component = components[j];
                if (!component.isNull())
                {
                    ImGui::BulletText("%s", component->getTypeName().c_str());
                }
            }

            ImGui::TreePop();
        }
    }

    ImGui::End();
}


void
GUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
    ImGui::Begin("Console");

    static ImGuiTextFilter filter; // Filtro de búsqueda
    filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);

    ImGui::Separator();

    ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

    for (const auto& pair : programMessages) {
        // Establece color según el tipo de mensaje
        ImVec4 color;
        switch (pair.first) {
        case ConsolErrorType::ERROR:
            color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); // Rojo para errores
            break;
        case ConsolErrorType::WARNING:
            color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f); // Amarillo para advertencias
            break;
        case ConsolErrorType::INFO:
        default:
            color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f); // Gris para mensajes de información
            break;
        }

        for (const auto& message : pair.second) {
            if (!filter.PassFilter(message.c_str())) continue; // Filtrar mensajes según el filtro de búsqueda

            ImGui::PushStyleColor(ImGuiCol_Text, color);
            ImGui::Text("[%d] %s", pair.first, message.c_str());
            ImGui::PopStyleColor();
        }
    }

    // Desplazamiento automático al final
    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
        ImGui::SetScrollHereY(1.0f);

    ImGui::EndChild();
    ImGui::End();
}
