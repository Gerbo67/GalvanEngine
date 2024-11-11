#include "ECS/Actor.h"
#include "Prerequisites.h"
#include "ShapeFactory.h"
#include "Transform.h"
#include "Services/NotificationService.h"

/**
 * @brief Constructor de la clase Actor.
 * @param actorName Nombre del actor.
 */
Actor::Actor(std::string actorName) {
    NotificationService& notifier = NotificationService::getInstance();
    
    // Configurar nombre del Actor.
    m_name = actorName;

    // Configurar Shape.
    EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
    addComponent(shape);

    // Configurar Transform.
    EngineUtilities::TSharedPointer<Transform> transform = EngineUtilities::MakeShared<Transform>();
    addComponent(transform);
    
    // Configurar Sprite.

    // Notify that the actor was created correctly
    notifier.Log("Actor named " + m_name + " was created.");
}

/**
 * @brief Actualiza el estado del actor.
 * @param deltaTime Tiempo transcurrido desde la última actualización.
 */
void
Actor::update(float deltaTime) {
    auto transform = getComponent<Transform>();
    auto shape = getComponent<ShapeFactory>();

    if(transform && shape) {
        shape->setPosition(transform->getPosition());
        shape->setRotation(transform->getRotation().x);
        shape->setScale(transform->getScale());
    }
}

/**
 * @brief Renderiza los componentes del actor.
 * @param window Contexto de la ventana para operaciones gráficas.
 */
void
Actor::render(Window& window) {
    for (unsigned int i = 0; i < components.size(); i++) {
        if(components[i].dynamic_pointer_cast<ShapeFactory>()) {
            window.draw(*components[i].dynamic_pointer_cast<ShapeFactory>()->getShape());
        }
    }
}