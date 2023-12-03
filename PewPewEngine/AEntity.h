#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace PewPewEngine {
	class Application;

	class AEntity : public sf::Transformable, public sf::Drawable
	{
	protected:
		std::string _id;
		std::string _name;

	public:
		Application* _app;

		AEntity(std::string name, int id, Application* app);

		virtual void Awake();
		virtual void Start();
		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);
		
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		std::string GetID();
		std::string GetName();
		sf::Transformable transform;
	};
}

