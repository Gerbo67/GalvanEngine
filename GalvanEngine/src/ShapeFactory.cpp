﻿#include "ShapeFactory.h"

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType) {
    m_shapeType = shapeType;
    switch (shapeType) {
    case NONE: {
            return nullptr;
        }
    case CIRCLE: {
            sf::CircleShape* circle = new sf::CircleShape(10.0f);
            circle->setFillColor(sf::Color::White);
            m_shape = circle;
            return circle;
        }
    case RECTANGLE: {
            sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(100.0f, 50.0f));
            rectangle->setFillColor(sf::Color::White);
            m_shape = rectangle;
            return rectangle;
        }
    case TRIANGLE: {
            sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3);
            triangle->setFillColor(sf::Color::White);
            m_shape = triangle;
            return triangle;
        }
    default:
        return nullptr;
    }
}

void
ShapeFactory::setPosition(float x, float y) {
    m_shape->setPosition(x, y);
}

void
ShapeFactory::setPosition(const sf::Vector2f& position) {
    m_shape->setPosition(position);
}

void
ShapeFactory::setFillColor(const sf::Color& color) {
    m_shape->setFillColor(color);
}

void
ShapeFactory::Seek(const sf::Vector2f& targetPosition,
                   float speed,
                   float deltaTime,
                   float range) {
    // Obtener la posición actual de mi shape
    sf::Vector2f shapePosition = m_shape->getPosition();

    // Calcular la dirección desde el círculo hacia el objetivo
    // Nota: Dirección es la pi - pf
    sf::Vector2f direction = targetPosition - shapePosition;

    // Calcular la distancia al objetivo
    float lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // Sí la distancia es mayor que el rango, mover la shape hacia el objetivo
    if (lenght > range)
    {
        direction /= lenght;
        m_shape->move(direction * speed * deltaTime);
    }
}

// NUEVO CODIGO DE PRACTICA
void
ShapeFactory::MoveTriangle(const std::vector<sf::Vector2f>& points, int& targetIndex, float speed, float deltaTime) {
    // Obtener la posición actual del triángulo
    sf::Vector2f currentPos = m_shape->getPosition();
    
    // Obtener el objetivo actual
    sf::Vector2f targetPos = points[targetIndex];
    
    // Calcular la dirección desde la posición actual hacia el objetivo
    sf::Vector2f direction = targetPos - currentPos;
    
    // Calcular la distancia al objetivo
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    // Si la distancia es mayor que una pequeña distancia
    if (length > 10.0f) {
        direction /= length;
        m_shape->move(direction * speed * deltaTime);
    }
    else {
        // Cambiar al siguiente objetivo en la secuencia
        targetIndex = (targetIndex + 1) % points.size();
    }
}
