#include "Physics.h"
#include "Acomponent.h"
#include "Rigibody.h"
#include "Application.h"

PewPewEngine::Physics::Physics() : _gravity(0.f, 0.f), _world(_gravity)
{
	std::cout << "add physic" << std::endl;
}

void PewPewEngine::Physics::Update(float deltatime, Application* app)
{
	for (AComponent* comp : app->_components) {
		Rigibody* rb = dynamic_cast<Rigibody*>(comp);
		if (rb != nullptr) {
			rb->getBody()->SetTransform(b2Vec2(rb->_parent->getPosition().x, rb->_parent->getPosition().y), rb->_parent->getRotation());
		}
	}

	int velocityIterations = 6;
	int positionIterations = 2;

	_world.Step(deltatime, velocityIterations, positionIterations);

	for (AComponent* comp : app->_components) {
		Rigibody* rb = dynamic_cast<Rigibody*>(comp);
		if (rb != nullptr) {
			rb->_parent->setPosition(rb->getBody()->GetPosition().x, rb->getBody()->GetPosition().y);
		}
	}

	//_world.ClearForces();

	std::cout << "update physic" << std::endl;
}

b2World* PewPewEngine::Physics::getWorld()
{
	return &_world;
}