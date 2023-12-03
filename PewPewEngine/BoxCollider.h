#pragma once
#include<box2d/box2d.h>
#include "Collider.h"
#include "AComponent.h"

namespace PewPewEngine {
	class BoxCollider : public Collider
	{
	protected:
		b2PolygonShape _shape;
		float _sizeX;
		float _sizeY;

	public:
		
		BoxCollider();
		BoxCollider(AEntity* parent, int id);
		void setSize(float sizeX, float sizeY);

		// Hérité via Collider
		b2Shape* getColliderShape() override;
	};
};
