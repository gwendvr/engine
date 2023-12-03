#pragma once
#include<box2d/box2d.h>
#include "AComponent.h"
#include "physics.h"

namespace PewPewEngine {
	class Rigibody : public AComponent
	{
	protected:
		b2BodyDef _bodyDef;
		b2Body* _body;

	public:

		Rigibody(AEntity* parent, int id);
		Rigibody();

		void createBody(Physics* physic);
		void setTypeBody(b2BodyType type);
		void setBodyPos(float x, float y);
		void setLinearVelocity(const b2Vec2& v);
		void setAngularVelocity(float omega);

		void getBodyPos();
		void getBodyAngle();
		void getLinearVelocity();
		void getAngularVelocity();
		b2Body* getBody();
	};
};

