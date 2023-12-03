#pragma once
#include<box2d/box2d.h>
#include "AComponent.h"

namespace PewPewEngine {
	class Collider : public AComponent
	{
	protected:
		b2FixtureDef _fixtureDef;
		b2Fixture* _fixture;

	public:

		Collider();
		Collider(AEntity* parent, int id);

		void createFixture(b2Body* body);
		virtual b2Shape* getColliderShape() = 0;

		void setDensity(float density);
		void setFriction(float friction);
	};
}
