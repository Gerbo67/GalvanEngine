#include "BaseApp.h"

#include "ShapeFactory.h"
#include "Transform.h"
#include "Services\NotificationService.h"

BaseApp::~BaseApp()
{
    NotificationService& notifier = NotificationService::getInstance();
    notifier.saveMessagesToFile("LogData.txt");
}

/**
 * @brief Ejecuta la aplicación base.
 * @return 0 si la ejecución es exitosa, otro valor en caso contrario.
 */
int
BaseApp::run() {
    NotificationService& notifier = NotificationService::getInstance();
    
    if (!initialize()) {
        notifier.addMessage(ConsolErrorType::ERROR, "Initializes result on a false statemente, check method validations");
        notifier.saveMessagesToFile("LogData.txt");
        ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
    } else {
        notifier.addMessage(ConsolErrorType::INFO, "All programs were initialized correctly");
    }

    m_GUI.init();
    
    while (m_window->isOpen()) {
        m_window->handleEvents();
        update();
        render();
    }

    cleanup();
    return 0;
}

/**
 * @brief Inicializa la aplicación base.
 * @return true si la inicialización es exitosa, false en caso contrario.
 */
bool
BaseApp::initialize() {
    NotificationService& notifier = NotificationService::getInstance();
    m_window = new Window(1920, 1080, "Galvan Engine");
    if (!m_window) {
        ERROR("BaseApp", "initialize", "Error on window creation, var is null");
        return false;
    }

    // Actor de Circuito
    Track = EngineUtilities::MakeShared<Actor>("Track");
    if (!Track.isNull()) {
        Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

        // Establecer posición, rotación y escala desde Transform
        Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
        Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Track->getComponent<Transform>()->setScale(sf::Vector2f(11.0f, 12.0f));

        // Insertar textura
        if(!texture.loadFromFile("circuit.png")) {
            std::cout << "Error de carga de textura" << std::endl;
            return -1; // Manejar error de carga
        }
        
        Track->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
    }
    m_actors.push_back(Track);

    // Actor de Círculo
    Circle = EngineUtilities::MakeShared<Actor>("Circle");
    if (!Circle.isNull()) {
        Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
        //Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

        // Establecer posición, rotación y escala desde Transform
        Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
        Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));

        // Insertar textura
        if(!characterTexture.loadFromFile("Characters/tile005.png")) {
            std::cout << "Error de carga de textura" << std::endl;
            return -1; // Manejar error de carga
        }
        
        Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&characterTexture);
    }
    m_actors.push_back(Circle);

    // Actor de Triángulo
    Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
    if (!Triangle.isNull()) {
        Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
        Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
        Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
        Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
    }
    m_actors.push_back(Triangle);

    return true;
}

/**
 * @brief Actualiza el estado de la aplicación.
 */
void
BaseApp::update() {
    m_window->update();
    
    // Posición del ratón
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
    sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // Actualizar los actores
    for (auto& actor : m_actors) {
        if (!actor.isNull()) {
            actor->update(m_window->deltaTime.asSeconds());
            if (actor->getName() == "Circle") {
                updateMovement(m_window->deltaTime.asSeconds(), actor);
            }
        }
    }
    
    // if (!Track.isNull()) {
    //     Track->update(m_window->deltaTime.asSeconds());
    // }
    //
    // if (!Triangle.isNull()) {
    //     Triangle->update(m_window->deltaTime.asSeconds());
    // }
    //
    // if (!Circle.isNull()) {
    //     Circle->update(m_window->deltaTime.asSeconds());
    //     /*Circle->getComponent<ShapeFactory>()->Seek(mousePosF, 200.0f, deltaTime.asSeconds(), 10.0f);*/
    //     updateMovement(m_window->deltaTime.asSeconds(), Circle);
    // }
}

/**
 * @brief Renderiza los elementos de la aplicación.
 */
void
BaseApp::render() {
    NotificationService& notifier = NotificationService::getInstance();
    m_window->clear();

    // Update the actors
    for (auto& actor : m_actors) {
        if (!actor.isNull()) {
            actor->render(*m_window);
        }
    }
    
    // if (!Track.isNull()) {
    //     Track->render(*m_window);
    // }
    //
    // if (!Circle.isNull()) {
    //     Circle->render(*m_window);
    // }
    //
    // if (!Triangle.isNull()) {
    //     Triangle->render(*m_window);
    // }

    //sf::Texture texture = m_window->renderTexture->getTexture();
    //ImGui::Image((void*)(intptr_t)texture.getNativeHandle(), ImVec2(800, 600));
    
    // // Configuración del estilo y colores (opcional)
    // ImGuiStyle& style = ImGui::GetStyle();
    // // Aquí puedes configurar el estilo si lo deseas
    //
    // // Comienzo de la interfaz
    // ImGui::Begin("Panel Neobrutalista");
    //
    // // Texto de bienvenida
    // ImGui::Text("Bienvenido a mi interfaz");
    //
    // // **Ventana de Jerarquía**
    // ImGui::Begin("Jerarquia");
    //
    // // Lista simple de elementos (nombres de los objetos)
    // static const char* items[] = { "Camara", "Luz", "Jugador", "Enemigo 1", "Enemigo 2" };
    // static int selected = -1; // Índice del elemento seleccionado
    //
    // // Mostrar la lista de elementos
    // for (int i = 0; i < IM_ARRAYSIZE(items); i++)
    // {
    //     // Crear un identificador único para cada elemento
    //     char label[128];
    //     sprintf(label, "%s##%d", items[i], i);
    //
    //     // Mostrar el elemento como seleccionable
    //     if (ImGui::Selectable(label, selected == i))
    //     {
    //         selected = i; // Actualizar el elemento seleccionado
    //     }
    // }
    //
    // ImGui::End(); // Fin de la ventana de Jerarquía
    //
    // // **Ventana de Inspector**
    // ImGui::Begin("Inspector");
    //
    // if (selected != -1)
    // {
    //     // Mostrar y editar propiedades del elemento seleccionado
    //     char buffer[128];
    //     strcpy(buffer, items[selected]); // Copiar el nombre del elemento seleccionado
    //
    //     // Permitir editar el nombre
    //     if (ImGui::InputText("Nombre", buffer, IM_ARRAYSIZE(buffer)))
    //     {
    //         // Si el nombre ha cambiado, actualizarlo
    //         // Nota: Como 'items' es un arreglo de punteros a const char*, no podemos modificarlo directamente.
    //         // Para este ejemplo simple, ignoraremos la actualización real.
    //     }
    //
    //     // Propiedades de ejemplo
    //     static float position[3] = { 0.0f, 0.0f, 0.0f };
    //     ImGui::DragFloat3("Posicion", position, 0.1f);
    //
    //     static float rotation[3] = { 0.0f, 0.0f, 0.0f };
    //     ImGui::DragFloat3("Rotacion", rotation, 0.1f);
    //
    //     static float scale[3] = { 1.0f, 1.0f, 1.0f };
    //     ImGui::DragFloat3("Escala", scale, 0.1f);
    // }
    // else
    // {
    //     ImGui::Text("Seleccione un elemento de la jerarquia.");
    // }
    //
    // ImGui::End(); // Fin de la ventana de Inspector
    //
    // // Botón Aceptar
    // if (ImGui::Button("Aceptar")) {
    //     // Acción al pulsar el botón
    // }
    //
    // ImGui::End(); // Fin del Panel Neobrutalista

    
    // Mostrar el render en ImGui
    m_window->renderToTexture();  // Finaliza el render a la textura
    m_window->showInImGui();      // Muestra la textura en ImGui
    m_GUI.console(notifier.getNotifications());
    m_GUI.Outliner(m_actors); 
    m_window->render();
    m_window->display();
}

/**
 * @brief Libera los recursos y realiza limpieza.
 */
void
BaseApp::cleanup() {
    m_window->destroy();
    delete m_window;
}

/**
 * @brief Actualiza el movimiento del círculo.
 * @param deltaTime Tiempo transcurrido desde la última actualización.
 * @param circle Puntero compartido al actor círculo.
 */
void
BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
    // Verificar si el Circle es nulo
    if (!circle || circle.isNull()) {
        return;
    }

    // Obtener el componente Transform
    auto transform = circle->getComponent<Transform>();
    if (transform.isNull()) {
        return;
    }

    // Posición actual del destino (punto de recorrido)
    sf::Vector2f targetPos = waypoints[currentWaypoint];

    // Llamar al Seek del Transform
    transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

    // Obtener la posición actual del actor desde Transform
    sf::Vector2f currentPos = transform->getPosition();

    // Comprobar si el actor ha alcanzado el destino (o está cerca)
    float distanceToTarget = std::sqrt(
        std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

    if (distanceToTarget < 10.0f) {
        // Umbral para considerar que ha llegado
        currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
    }
}
