#pragma once
#include "Entity.h"
#include "Prerequisites.h"
#include <vector>
#include <string>

/**
 * @class Actor
 * @brief Representa una entidad en la escena.
 *
 * La clase Actor puede contener múltiples componentes que definen 
 * su comportamiento y apariencia. Es el objeto principal que se manipula 
 * y renderiza en la escena.
 */
class
Actor : Entity {
public:
    /**
     * @brief Constructor por defecto.
     */
    Actor() = default;

    /**
     * @brief Constructor con nombre de actor.
     * @param actorName Nombre del actor.
     */
    Actor(std::string actorName);

    /**
     * @brief Destructor por defecto.
     */
    virtual
    ~Actor() = default;

    /**
     * @brief Actualiza el actor.
     * @param deltaTime El tiempo transcurrido desde la última actualización.
     */
    void
    update(float deltaTime) override;

    /**
     * @brief Renderiza el actor.
     * @param window Contexto del dispositivo para operaciones gráficas.
     */
    void
    render(Window& window) override;

    /**
     * @brief Destruye el actor y libera los recursos asociados.
     */
    void
    destroy();

    /**
     * @brief Obtiene el nombre del actor.
     * @return Nombre del actor.
     */
    std::string getName() const
    {
        return m_name;
    }

    /**
     * @brief Establece el nombre del actor.
     * @param name El nuevo nombre del actor.
     */
    void
    setName(const std::string& name)
    {
        m_name = name;
    }

    /**
     * @brief Obtiene una lista de componentes del actor.
     * @return Lista de componentes.
     */
    const std::vector<EngineUtilities::TSharedPointer<Component>>&
    getComponents() const
    {
        return components;
    }

    /**
     * @brief Obtiene un componente específico del actor.
     * @tparam T Tipo del componente que se va a obtener.
     * @return Puntero compartido al componente, o nullptr si no se encuentra.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T>
    getComponent();

private:
    std::string m_name = "Actor"; ///< Nombre del actor.
};

/*
 * El propósito de esta función es buscar y devolver un componente especifico de un actor,
 * utilizando el tipo de componente especificado como argumento de la plantilla.
 * Si el componente no se encuentre, la función devuelve nullptr.
 */
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
 for (auto& component : components) {
  EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
  if (specificComponent) {
   return specificComponent;
  }
 }
 // Devuelve un TSharedPointer vacío si no se encuentra el componente
 return EngineUtilities::TSharedPointer<T>();
}
