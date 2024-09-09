#pragma once
#include <SFML/Graphics.hpp>


class BaseApp
{
public:
    BaseApp() = default;
    ~BaseApp() = default;

    // Funcion encargada de ejecutar la apliacion en main
    int run();

    // Funcion de inicializacion
    void initialize();

    // Funcion de manejo de datos
    void handleEvents();

    // Funcion que se actualiza por frame
    void update();

    // Funcion de renderizado
    void render();

    // Funcion para liberacion de recursos
    void cleanup();

private:
    sf::RenderWindow* window;
    sf::CircleShape* shape;
};
