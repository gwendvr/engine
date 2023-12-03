#pragma once
#include <iostream>
#include<box2d/box2d.h>

namespace PewPewEngine {
	class Application;

	class Physics
	{
	protected:
		b2Vec2 _gravity;
		b2World _world;

	public:
		Physics();
		void Update(float deltatime, Application* app);
		b2World* getWorld();
	};
};

