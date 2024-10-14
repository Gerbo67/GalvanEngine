#pragma once
#include "Prerequisites.h"
#include "Component.h"

class
Window;

/**
 * @class Entity
 * @brief Representa cualquier objeto en el juego o la aplicación gráfica.
 *
 * La clase Entity se usa como base para mejorar la organización y jerarquía 
 * en la escena. Proporciona funcionalidades básicas comunes a todos los objetos.
 */
class
Entity {
public:
    /**
     * @brief Destructor virtual.
     */
    virtual
    ~Entity() = default;

    /**
     * @brief Método virtual puro para actualizar la entidad.
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     */
    virtual void
    update(float deltaTime) = 0;

    /**
     * @brief Método virtual puro para renderizar la entidad.
     * @param window Contexto del dispositivo para operaciones gráficas.
     */
    virtual void
    render(Window& window) = 0;

    /**
     * @brief Agrega un componente a la entidad.
     * @tparam T Tipo del componente, debe derivar de Component.
     * @param component Puntero compartido al componente que se va a agregar.
     */
    template <typename T>
    void
    addComponent(EngineUtilities::TSharedPointer<T> component) {
        static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
        components.push_back(component.template dynamic_pointer_cast<Component>());
    }

    /**
     * @brief Obtiene un componente de la entidad.
     * @tparam T Tipo del componente que se va a obtener.
     * @return Puntero compartido al componente, o nullptr si no se encuentra.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T>
    getComponent() {
        for (auto& component : components) {
            EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
            if (specificComponent) {
                return specificComponent;
            }
        }
        return EngineUtilities::TSharedPointer<T>();
    }

protected:
    bool isActive; ///< Indica si la entidad está activa.
    int id; ///< Identificador único de la entidad.

    std::vector<EngineUtilities::TSharedPointer<Component>> components; ///< Lista de componentes de la entidad.
};
