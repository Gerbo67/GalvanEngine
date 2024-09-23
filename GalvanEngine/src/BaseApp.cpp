#include "BaseApp.h"

int
BaseApp::run()
{
    if (!initialize())
    {
        ERROR("BaseApp", "run", "Initialize result on a false statement, check method validations");
    }
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
bool
BaseApp::initialize()
{
    m_window = new Window(800, 600, "Galvan Engine");
    if (!m_window)
    {
        ERROR("BaseApp", "initialize", "Error on window creation, var is null");
        return false;
    }
    shape = new sf::CircleShape(10.0f);

    if (!shape)
    {
        ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
        return false;
    }

    shape->setFillColor(sf::Color::Blue);
    shape->setPosition(200.0f, 200.0f);

    Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
    if (!Triangle.isNull())
    {
        Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
    }

    // Triangulo = m_shapeFactory.createShape(ShapeType::TRIANGLE);
    // if (!Triangulo)
    // {
    //     ERROR("BaseApp", "initialize", "Error on triangulo creation, var is null");
    //     return false;
    // }
    
    return true;
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
    if(!Triangle.isNull())
    {
        m_window->draw(*Triangle->getComponent<ShapeFactory>()->m_shape);
    }
    // m_window->draw(*Triangulo);
    m_window->display();
}

void
BaseApp::cleanup()
{
    m_window->destroy();
    delete m_window;
    delete shape;
    // delete Triangulo;
}
