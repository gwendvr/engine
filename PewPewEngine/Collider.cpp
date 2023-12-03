#include "Collider.h"

PewPewEngine::Collider::Collider()
{
}

PewPewEngine::Collider::Collider(AEntity* parent, int id) : AComponent(id)
{
	_parent = parent;
}

void PewPewEngine::Collider::createFixture(b2Body* body)
{
	_fixtureDef.shape = getColliderShape();
	body->CreateFixture(&_fixtureDef);
}

void PewPewEngine::Collider::setDensity(float density)
{
	_fixtureDef.density = density;
	if (_fixture) {
		_fixture->SetDensity(density);
	}
}

void PewPewEngine::Collider::setFriction(float friction)
{
	_fixtureDef.friction = friction;
	if (_fixture) {
		_fixture->SetFriction(friction);
	}
}
