#include "GUI.h"

#include "ShapeFactory.h"
#include "Transform.h"
#include "ECS/Actor.h"

class
ShapeFactory;

/**
 * @brief Inicializa la GUI y configura el estilo.
 */
void
GUI::init() {
    // Configurar estilo de GUI
    setupGUIStyle();
}

/**
 * @brief Actualiza la GUI. Este método puede ser extendido para incluir lógica de actualización en cada frame.
 */
void
GUI::update() {
}

/**
 * @brief Renderiza la GUI. Método utilizado para añadir lógica de renderizado.
 */
void
GUI::render() {
}

/**
 * @brief Destruye la GUI y libera los recursos asociados.
 */
void
GUI::destroy() {
}

/**
 * @brief Configura el estilo de la GUI utilizando colores y espaciamiento específicos.
 */
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

/**
 * @brief Muestra una consola con los mensajes del programa.
 * @param programMessages Mapa de mensajes del programa categorizados por tipo de error.
 */
void
GUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
    ImGui::Begin("Console");

    static ImGuiTextFilter filter; // Filtro de búsqueda
    filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);

    ImGui::Separator();

    ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

    for (const auto& pair : programMessages) {
        // Establecer color según el tipo de mensaje
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

/**
 * @brief Muestra un componente Outliner que permite organizar y seleccionar actores.
 * @param actors Vector de actores a mostrar en el Outliner.
 */
void
GUI::Outliner(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
    ImGui::Begin("Outliner");

    // Iterar sobre los actores
    for (size_t i = 0; i < actors.size(); ++i) {
        auto& actor = actors[i];
        if (actor.isNull())
            continue;

        // Establecer flags del nodo
        ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;

        // Resaltar el actor seleccionado
        if (actor == m_actors)
            node_flags |= ImGuiTreeNodeFlags_Selected;

        // Crear un nodo de árbol para el actor
        bool node_open = ImGui::TreeNodeEx((void*)(intptr_t)i, node_flags, actor->getName().c_str());

        // Manejar la selección
        if (ImGui::IsItemClicked()) {
            m_actors = actor;
        }

        // Si el nodo está abierto, mostrar sus componentes
        if (node_open)
        {
            // Mostrar componentes
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

/**
 * @brief Muestra un componente para agregar actores con un tipo de forma específico.
 * @param actors Vector de actores donde se añadirá el nuevo actor.
 */
void
GUI::PlaceActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
    ImGui::Begin("Place Actors");

    static char actorName[128] = "";
    ImGui::InputText("Name", actorName, IM_ARRAYSIZE(actorName));

    static int shapeType = 0;
    const char* shapeTypes[] = {"NONE", "CIRCLE", "RECTANGLE", "TRIANGLE"};
    ImGui::Combo("Shape Type", &shapeType, shapeTypes, IM_ARRAYSIZE(shapeTypes));

    if (ImGui::Button("Create Actor")) {
        EngineUtilities::TSharedPointer<Actor> newActor = EngineUtilities::MakeShared<Actor>(actorName);

        auto shapeFactory = newActor->getComponent<ShapeFactory>();
        if (shapeFactory) {
            switch (shapeType) {
            case 1:
                shapeFactory->createShape(ShapeType::CIRCLE);
                break;
            case 2:
                shapeFactory->createShape(ShapeType::RECTANGLE);
                break;
            case 3:
                shapeFactory->createShape(ShapeType::TRIANGLE);
                break;
            }
        }
        else {
            ImGui::Text("ShapeFactory component not found.");
        }

        actors.push_back(newActor);
    }

    ImGui::End();
}

/**
 * @brief Muestra el inspector que permite ver y editar las propiedades de los actores y sus componentes.
 * @param actors Vector de actores a mostrar en el inspector.
 */
void
GUI::Inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors) {
    ImGui::Begin("Inspector");

    if (m_actors) {
        auto& actor = m_actors;

        char actorName[128];
        snprintf(actorName, sizeof(actorName), "%s", actor->getName().c_str());
        if (ImGui::InputText("Name", actorName, sizeof(actorName))) {
            actor->setName(actorName);
        }

        const auto& components = actor->getComponents();
        for (size_t j = 0; j < components.size(); ++j) {
            auto& component = components[j];
            if (!component.isNull()) {
                ImGui::Text("%s", component->getTypeName().c_str());

                if (component->getTypeName() == "Transform") {
                    auto transform = actor->getComponent<Transform>();

                    if (transform) {
                        sf::Vector2f pos = transform->getPosition();
                        if (ImGui::DragFloat2("Position", &pos.x)) {
                            transform->setPosition(pos);
                        }

                        sf::Vector2f scale = transform->getScale();
                        if (ImGui::DragFloat2("Scale", &scale.x)) {
                            transform->setScale(scale);
                        }

                        sf::Vector2f rot = transform->getRotation();
                        if (ImGui::DragFloat2("Rotation", &rot.x)) {
                            transform->setRotation(rot);
                        }
                    }
                }
            }
        }
    }

    ImGui::End();
}
