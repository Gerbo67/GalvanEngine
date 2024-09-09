#pragma once
#include <SFML/Graphics.hpp>

#include "Window.h"

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
    void
    initialize();

    // Funcion que se actualiza por frame
    void
    update();

    // Funcion de renderizado
    void
    render();

    //Funcion de liberacion de memoria
    void
    cleanup();

private:
    Window* m_window;
    //Variables Globales
    sf::RectangleShape* shape;
    sf::CircleShape* shape2;
};
