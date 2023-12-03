#include "Rigibody.h"
#include "AEntity.h"
#include "Application.h"
#include "Collider.h"

PewPewEngine::Rigibody::Rigibody(AEntity* parent, int id) : AComponent(id)
{
	_parent = parent;
}

PewPewEngine::Rigibody::Rigibody()
{
	
}

void PewPewEngine::Rigibody::createBody(Physics* physic)
{
	_body = physic->getWorld()->CreateBody(&_bodyDef);
	for (AComponent* comp : _parent->_app->_components) {
		if (_parent->_app->_linkBetweenComponentAndEntity[comp->GetID()] == _parent->GetID()) {
			Collider* col = dynamic_cast<Collider*>(comp);
			if (col != nullptr) {
				col->createFixture(_body);
			}
		}
	}
}

void PewPewEngine::Rigibody::setTypeBody(b2BodyType type)
{
	_bodyDef.type = type;
}

void PewPewEngine::Rigibody::setBodyPos(float x, float y)
{
	_bodyDef.position.Set(x, y);
}

void PewPewEngine::Rigibody::setLinearVelocity(const b2Vec2 &v)
{
	_body->SetLinearVelocity(v);
}

void PewPewEngine::Rigibody::setAngularVelocity(float omega)
{
	_body->SetAngularVelocity(omega);
}

void PewPewEngine::Rigibody::getBodyPos()
{
	_body->GetPosition();
}

void PewPewEngine::Rigibody::getBodyAngle()
{
	_body->GetAngle();
}

void PewPewEngine::Rigibody::getLinearVelocity()
{
	_body->GetLinearVelocity();
}

void PewPewEngine::Rigibody::getAngularVelocity()
{
	_body->GetAngularVelocity();
}

b2Body* PewPewEngine::Rigibody::getBody()
{
	return _body;
}
