#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "ShapeFactory.h"
#include "ECS/Actor.h"

class
BaseApp
{
public:
    BaseApp() = default;
    ~BaseApp() = default;

    // Funcion que corre el programa en main
    int
    run();

    // Funcion de inicializacion
    bool
    initialize();

    // Funcion que se actualiza por frame
    void
    update();

    // Funcion de renderizado
    void
    render();

    // Funcion de liberacion de memoria
    void
    cleanup();

private:
    // Variables Globales
    Window * m_window;
    sf::CircleShape* shape;
    EngineUtilities::TSharedPointer<Actor> Triangle;
    // ShapeFactory m_shapeFactory;
    // sf::Shape* Triangulo;
};
