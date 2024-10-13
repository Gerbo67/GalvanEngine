#include "BaseApp.h"
#include "Transform.h"

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		deltaTime = clock.restart();
		update();
		render();
	}

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}

	// Circle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
		Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

		// Establecer posici�n, rotaci�n y escala desde Transform
		Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
		Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
		Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
	}

	// Triangle Actor
	Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
	if (!Triangle.isNull()) {
		Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
		Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
		Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
		Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
	}

	return true;
}

void
BaseApp::update() {
	// Mouse Position
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y));

	if (!Triangle.isNull()) {
		Triangle->update(deltaTime.asSeconds());
	}
	if (!Circle.isNull()) {
		Circle->update(deltaTime.asSeconds());
		/*Circle->getComponent<ShapeFactory>()->Seek(mousePosF, 200.0f, deltaTime.asSeconds(), 10.0f);*/
		updateMovement(deltaTime.asSeconds(), Circle);
	}

}

void
BaseApp::render() {
	m_window->clear();
	Circle->render(*m_window);
	Triangle->render(*m_window);
	m_window->display();
}

void
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
}

void
BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
	// Verificar si el Circle es nulo
	if (!circle || circle.isNull()) return;

	// Obtener el componente Transform
	auto transform = circle->getComponent<Transform>();
	if (transform.isNull()) return;

	// Posici�n actual del destino (punto de recorrido)
	sf::Vector2f targetPos = waypoints[currentWaypoint];

	// Llamar al Seek del Transform
	transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

	// Obtener la posici�n actual del actor desde Transform
	sf::Vector2f currentPos = transform->getPosition();

	// Comprobar si el actor ha alcanzado el destino (o est� cerca)
	float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

	if (distanceToTarget < 10.0f) { // Umbral para considerar que ha llegado
		currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a trav�s de los puntos
	}
}