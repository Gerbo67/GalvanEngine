#include "ShapeFactory.h"

/**
 * @brief Crea una forma del tipo especificado.
 * @param shapeType Tipo de la forma a crear.
 * @return Puntero a la forma creada.
 */
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
            sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f));
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

/**
 * @brief Establece la posición de la forma.
 * @param x Coordenada X.
 * @param y Coordenada Y.
 */
void
ShapeFactory::setPosition(float x, float y) {
    if (m_shape) {
        m_shape->setPosition(x, y);
    }
}

/**
 * @brief Establece la posición de la forma.
 * @param position Vector con la nueva posición.
 */
void
ShapeFactory::setPosition(const sf::Vector2f& position) {
    if (m_shape) {
        m_shape->setPosition(position);
    }
}

/**
 * @brief Establece el color de relleno de la forma.
 * @param color Color de relleno.
 */
void
ShapeFactory::setFillColor(const sf::Color& color) {
    if (m_shape) {
        m_shape->setFillColor(color);
    }
}

/**
 * @brief Establece la rotación de la forma.
 * @param angle Ángulo de rotación.
 */
void
ShapeFactory::setRotation(float angle) {
    if (m_shape) {
        m_shape->setRotation(angle);
    }
}

/**
 * @brief Establece la escala de la forma.
 * @param scl Vector con la nueva escala.
 */
void
ShapeFactory::setScale(const sf::Vector2f& scl) {
    if (m_shape) {
        m_shape->setScale(scl);
    }
}
