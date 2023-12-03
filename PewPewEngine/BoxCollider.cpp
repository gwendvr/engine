#include "BoxCollider.h"

PewPewEngine::BoxCollider::BoxCollider()
{
}

PewPewEngine::BoxCollider::BoxCollider(AEntity* parent, int id) {
	_parent = parent;
	_id = std::to_string(id);
}

void PewPewEngine::BoxCollider::setSize(float sizeX, float sizeY)
{
	_sizeX = sizeX;
	_sizeY = sizeY;
	_shape.SetAsBox(_sizeX, _sizeY);
}

b2Shape* PewPewEngine::BoxCollider::getColliderShape()
{
	return &_shape;
}
