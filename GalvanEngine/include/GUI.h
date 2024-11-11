﻿#pragma once
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

    /**
     * @brief Muestra el outliner con la lista de actores.
     * @param actors Vector de actores a listar.
     */
    void
    Outliner(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

    /**
    * @brief Muestra una consola con mensajes del programa.
    * @param programMessages Mapa de mensajes del programa categorizados por tipo de error.
    */
    void 
    console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages);
 
    /**
     * @brief Permite colocar actores en la escena.
     * @param actors Vector de actores en la escena.
     */
    void
    PlaceActors(std::vector<EngineUtilities::TSharedPointer<Actor>>& actors);
 
     /**
     * @brief Muestra el inspector del actor seleccionado con sus componentes.
     * @param actors Vector de actores a inspeccionar.
     */
    void
    Inspector(std::vector<EngineUtilities::TSharedPointer<Actor>> actors);

private:
    EngineUtilities::TSharedPointer<Actor> m_actors; ///< Actor seleccionado en el GUI.
};