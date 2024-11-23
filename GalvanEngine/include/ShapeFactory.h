#pragma once
#include "Prerequisites.h"
#include "ECS/Component.h"
#include "Window.h"

/**
 * @class ShapeFactory
 * @brief Responsable de crear y administrar formas geométricas.
 *
 * Proporciona métodos para configurar y crear diferentes tipos de formas 
 * (como círculos, triángulos, etc.) y define propiedades como el color de relleno.
 * Este componente es usado por los actores para renderizar formas en la escena.
 */
class
ShapeFactory : public Component {
public:
    /**
     * @brief Constructor por defecto.
     */
    ShapeFactory() = default;

    /**
     * @brief Destructor virtual.
     */
    virtual
    ~ShapeFactory() = default;

    /**
     * @brief Constructor con tipo de forma.
     * @param shapeType Tipo de la forma a crear.
     */
    ShapeFactory(ShapeType shapeType) :
        m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) { }

    /**
     * @brief Crea una forma del tipo especificado.
     * @param shapeType Tipo de la forma a crear.
     * @return Puntero a la forma creada.
     */
    sf::Shape*
    createShape(ShapeType shapeType);

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
     * @brief Establece la posición de la forma.
     * @param x Coordenada X.
     * @param y Coordenada Y.
     */
    void
    setPosition(float x, float y);

    /**
     * @brief Establece la posición de la forma.
     * @param position Vector con la nueva posición.
     */
    void
    setPosition(const sf::Vector2f& position);

    /**
     * @brief Establece el color de relleno de la forma.
     * @param color Color de relleno.
     */
    void
    setFillColor(const sf::Color& color);
 
    /**
     * @brief Establece la rotación de la forma.
     * @param angle Ángulo de rotación.
     */
    void
    setRotation(float angle);

    /**
     * @brief Establece la escala de la forma.
     * @param scl Vector con la nueva escala.
     */
    void
    setScale(const sf::Vector2f& scl);

    /**
     * @brief Mueve el triángulo a lo largo de los puntos especificados.
     * @param points Vector de posiciones objetivo.
     * @param targetIndex Índice del punto objetivo actual.
     * @param speed Velocidad del movimiento.
     * @param deltaTime Tiempo transcurrido desde la última actualización.
     */
    void
    MoveTriangle(const std::vector<sf::Vector2f>& points, int& targetIndex, float speed, float deltaTime);

    /**
     * @brief Obtiene la forma actual.
     * @return Puntero a la forma.
     */
    sf::Shape*
    getShape() {
        return m_shape;
    }

private:
    sf::Shape* m_shape; ///< Puntero a la forma gestionada.
    ShapeType m_shapeType; ///< Tipo de la forma gestionada.
};
