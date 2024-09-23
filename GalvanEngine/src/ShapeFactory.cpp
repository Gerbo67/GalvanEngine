﻿#include "ShapeFactory.h"

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType)
{
    m_shapeType = shapeType;
    switch (shapeType)
    {
    case NONE:
        {
            return nullptr;
        }
    case CIRCLE:
        {
            sf::CircleShape* circle = new sf::CircleShape(10.0f);
            circle->setFillColor(sf::Color::White);
            m_shape = circle;
            return circle;
        }
    case RECTANGLE:
        {
            sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(100.0f, 50.0f));
            rectangle->setFillColor(sf::Color::White);
            m_shape = rectangle;
            return rectangle;
        }
    case TRIANGLE:
        {
            sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3);
            triangle->setFillColor(sf::Color::White);
            m_shape = triangle;
            return triangle;
        }
    default:
        return nullptr;
    }
}
