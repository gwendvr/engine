#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace PewPewEngine {
	class AEntity;

	class AComponent : public sf::Drawable
	{
	protected:
		sf::CircleShape _shape;
		std::string _id;

	public:
		AEntity* _parent;
		AComponent();
		AComponent(int id);

		virtual void Awake();
		virtual void Start();
		virtual void Update(float deltaTime);
		virtual void LateUpdate(float deltaTime);
		std::string GetID();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	};
}

