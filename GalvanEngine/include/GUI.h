#pragma once
#include "Prerequisites.h"

class
Actor;

class
Window;

class
GUI {
public:
    GUI() = default;
    ~GUI() = default;

    /**
     * @brief Inicializa la ventana y sus recursos.
     */
    void
    init();

    /**
     * @brief Actualiza la ventana por cada frame.
     */
    void
    update();

    /**
     * @brief Renderiza el contenido de la ventana.
     */
    void
    render();

    /**
    * @brief Destruye la ventana y libera los recursos.
    */
    void
    destroy();

    /**
    * @brief Declara los estilos de la ventana.
    */
    void
    setupGUIStyle();

    void
    Outliner(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

    void 
    console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);

private:
    EngineUtilities::TSharedPointer<Actor> m_actors;
};