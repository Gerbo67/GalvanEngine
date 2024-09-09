#include "BaseApp.h"

int BaseApp::run()
{
    initialize();
    while (window->isOpen())
    {
        handleEvents();
        update();
        render();
    }

    cleanup();

    return 0;
}

// Funcion de inicializacion
void BaseApp::initialize()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Galvan Engine");
    shape = new sf::CircleShape(100.0f);
    shape->setFillColor(sf::Color::Green);
}

// Funcion de manejo de datos
void BaseApp::handleEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

// Funcion que se actualiza por frame
void BaseApp::update()
{
}

// Funcion de renderizado
void BaseApp::render()
{
    window->clear();
    window->draw(*shape);
    window->display();
}

void BaseApp::cleanup()
{
    delete window;
    delete shape;
}
