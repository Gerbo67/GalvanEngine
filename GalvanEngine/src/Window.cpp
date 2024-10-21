#include "Window.h"

/**
 * @brief Constructor que inicializa la ventana con las dimensiones y título especificados.
 * @param width Ancho de la ventana.
 * @param height Alto de la ventana.
 * @param title Título de la ventana.
 */
Window::Window(int width, int height, const std::string& title) {
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

    if (!m_window) {
        ERROR("Window", "Window", "CHECK CONSTRUCTOR");
    } else {
        MESSAGE("Window", "Window", "OK");
    }

    ImGui::SFML::Init(*m_window);  // Inicializa ImGui-SFML
}

/**
 * @brief Destructor que limpia los recursos de la ventana.
 */
Window::~Window() {
    ImGui::SFML::Shutdown();
    delete m_window;
}

/**
 * @brief Maneja los eventos de la ventana.
 */
void
Window::handleEvents() {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);

        switch (event.type) {
        case sf::Event::Closed:
            m_window->close();
            break;
        case sf::Event::Resized:
            // Manejar el evento de redimensionar
            // Obtener el nuevo tamaño de la ventana
            unsigned int newWidth = event.size.width;
            unsigned int newHeight = event.size.height;
            
            // Opcional: Redefinir el tamaño de la vista para ajustarse al nuevo tamaño de la ventana
            sf::View view = m_window->getView();
            view.setSize(static_cast<float>(newWidth), static_cast<float>(newHeight));
            m_window->setView(view);
            break;
        }
    }
}

/**
 * @brief Limpia el contenido de la ventana con el color predeterminado.
 */
void
Window::clear() {
    if (m_window != nullptr) {
        m_window->clear();
    } else {
        ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA");
    }
}

/**
 * @brief Muestra el contenido de la ventana en la pantalla.
 */
void
Window::display() {
    if (m_window != nullptr) {
        m_window->display();
    } else {
        ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA");
    }
}

/**
 * @brief Verifica si la ventana sigue abierta.
 * @return true si la ventana está abierta, false en caso contrario.
 */
bool
Window::isOpen() const {
    if (m_window != nullptr) {
        return m_window->isOpen();
    } else {
        ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA");
        return false;
    }
}

/**
 * @brief Dibuja un objeto que puede ser dibujado en la ventana.
 * @param drawable Referencia a un objeto SFML que puede ser dibujado.
 */
void
Window::draw(const sf::Drawable& drawable) {
    if (m_window != nullptr) {
        m_window->draw(drawable);
    } else {
        ERROR("Window", "draw", "CHECK FOR WINDOW POINTER DATA");
    }
}

/**
 * @brief Obtiene el objeto interno SFML RenderWindow.
 * @return Un puntero al objeto interno SFML RenderWindow.
 */
sf::RenderWindow*
Window::getWindow() {
    if (m_window != nullptr) {
        return m_window;
    } else {
        ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA");
        return nullptr;
    }
}

void
Window::update() {
    // Almacena el deltaTime una sola vez
    deltaTime = clock.restart();
    // Usa ese deltaTime para actualizar ImGui
    ImGui::SFML::Update(*m_window, deltaTime);
}

void
Window::render() {
    ImGui::SFML::Render(*m_window);
}

/**
 * @brief Destruye la ventana y libera los recursos.
 */
void
Window::destroy() {
    SAFE_PTR_RELEASE(m_window);
}