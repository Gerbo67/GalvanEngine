#pragma once
#include "Prerequisites.h"
#include "ECS\Component.h"

class
    Texture : public Component
{
public:
    Texture() = default;

    Texture(std::string textureName, std::string extension) : m_textureName(textureName),
                                                              m_extension(extension),
                                                              Component(ComponentType::TEXTURE)
    {
        if (!m_texture.loadFromFile(m_textureName + "." + m_extension))
        {
            std::cout << "Error de carga de textura: " << m_textureName << "." << m_extension << std::endl;
        }
    }

    virtual
    ~Texture() = default;

    sf::Texture& getTexture()
    {
        return m_texture;
    }

    // Implementaci�n de los m�todos virtuales puros
    void update(float deltaTime) override
    {
        // L�gica de actualizaci�n de la textura (si es necesario)
    }

    void render(Window window) override
    {
        // L�gica de renderizado de la textura (si es necesario)
    }

private:
    std::string m_textureName;
    std::string m_extension;
    sf::Texture m_texture;
};
