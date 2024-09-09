#include "BaseApp.h"

int
BaseApp::run()
{
    initialize();

    while (m_window->isOpen())
    {
        m_window->handleEvents();
        update();
        render();
    }

    cleanup();

    return 0;
}

// Funcion de inicializacion
void
BaseApp::initialize()
{
    // Init window
    m_window = new Window(800, 600, "Mi ventana SFML");

    // Init Objects
    shape2 = new sf::CircleShape(300, 300);
    shape2->setFillColor(sf::Color::Cyan);
    shape2->setOutlineThickness(20);
    shape2->setOutlineColor(sf::Color::Red);
}

// Funcion que se actualiza por frame
void
BaseApp::update()
{
}

// Funcion de renderizado
void
BaseApp::render()
{
    m_window->clear();
    m_window->draw(*shape);
    m_window->display();
}

void
BaseApp::cleanup()
{
    m_window->destroy();
    delete m_window;
    delete shape;
}
