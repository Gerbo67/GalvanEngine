#pragma once
#include "Prerequisites.h"
#include "ECS/Component.h"
#include "Window.h"

/**
 * @class Transform
 * @brief Maneja la posición, rotación y escala de un Actor.
 *
 * La clase Transform es crucial para definir dónde se encuentra un actor 
 * en el espacio de la escena y cómo se mueve y rota. También puede incluir 
 * métodos para transformar (mover) el Actor.
 */
class
Transform : public Component {
public:
    /**
     * @brief Constructor por defecto.
     */
    Transform() : position(0.0f, 0.0f),
                  rotation(0.0f, 0.0f),
                  scale(1.0f, 1.0f),
                  Component(ComponentType::TRANSFORM) { }

    /**
     * @brief Destructor virtual.
     */
    virtual
    ~Transform() = default;

    /**
     * @brief Actualiza el componente de malla.
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     */
    void
    update(float deltaTime) override { }

    /**
     * @brief Renderiza el componente de malla.
     * @param window Contexto del dispositivo para operaciones gráficas.
     */
    void
    render(Window window) override { }

    /**
     * @brief Destruye el componente.
     */
    void
    destroy() { }

    /**
     * @brief Actualiza la posición del objeto buscando un objetivo.
     * @param targetPosition Posición del objetivo.
     * @param speed Velocidad del movimiento.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     * @param range Rango dentro del cual el movimiento buscará el objetivo.
     */
    void
    Seek(const sf::Vector2f& targetPosition,
         float speed,
         float deltaTime,
         float range) {
        sf::Vector2f direction = targetPosition - position;
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (length > range) {
            direction /= length; // Normaliza el vector
            position += direction * speed * deltaTime;
        }
    }

    /**
     * @brief Establece la posición del objeto.
     * @param _position Nueva posición.
     */
    void
    setPosition(const sf::Vector2f& _position) {
        position = _position;
    }

    /**
     * @brief Establece la rotación del objeto.
     * @param _rotation Nueva rotación.
     */
    void
    setRotation(const sf::Vector2f& _rotation) {
        rotation = _rotation;
    }

    /**
     * @brief Establece la escala del objeto.
     * @param _scale Nueva escala.
     */
    void
    setScale(const sf::Vector2f& _scale) {
        scale = _scale;
    }

    /**
     * @brief Obtiene la posición del objeto.
     * @return Referencia a la posición del objeto.
     */
    sf::Vector2f&
    getPosition() {
        return position;
    }

    /**
     * @brief Obtiene la rotación del objeto.
     * @return Referencia a la rotación del objeto.
     */
    sf::Vector2f&
    getRotation() {
        return rotation;
    }

    /**
     * @brief Obtiene la escala del objeto.
     * @return Referencia a la escala del objeto.
     */
    sf::Vector2f&
    getScale() {
        return scale;
    }

    virtual std::string getTypeName() const override { return "Transform"; }

private:
    sf::Vector2f position; ///< Posición del objeto.
    sf::Vector2f rotation; ///< Rotación del objeto.
    sf::Vector2f scale; ///< Escala del objeto.
};
