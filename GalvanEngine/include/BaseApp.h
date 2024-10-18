#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "ECS/Actor.h"

/**
 * @class BaseApp
 * @brief Clase base para la aplicación.
 *
 * La clase BaseApp controla el ciclo principal de la aplicación, manejando 
 * la inicialización, actualización, renderizado y limpieza. Mantiene la 
 * aplicación en funcionamiento mientras la ventana esté abierta.
 */
class
BaseApp {
public:
    BaseApp() = default; ///< Constructor por defecto.
    ~BaseApp() = default; ///< Destructor por defecto.

    /**
     * @brief Función encargada de ejecutar la aplicación en main.
     * @return Código de estado de la ejecución.
     */
    int
    run();

    /**
     * @brief Función de inicialización.
     * @return true si la inicialización es exitosa, false en caso contrario.
     */
    bool
    initialize();

    /**
     * @brief Función que se actualiza por frame.
     */
    void
    update();

    /**
     * @brief Función de renderizado.
     */
    void
    render();

    /**
     * @brief Realiza la limpieza de recursos.
     */
    void
    cleanup();

    /**
     * @brief Actualiza el movimiento del círculo.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     * @param circle Puntero compartido al actor círculo.
     */
    void
    updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
    Window* m_window; ///< Puntero a la ventana de la aplicación.
    EngineUtilities::TSharedPointer<Actor> Triangle; ///< Puntero compartido al Actor del triángulo.
    EngineUtilities::TSharedPointer<Actor> Circle; ///< Puntero compartido al Actor del círculo.

    int currentWaypoint = 0; ///< Índice del punto de recorrido actual.

    std::vector<sf::Vector2f> waypoints = {
        {100.0f, 100.0f},
        {400.0f, 100.0f},
        {400.0f, 400.0f},
        {100.0f, 400.0f}
    }; ///< Lista de puntos de recorrido (waypoints).
};
