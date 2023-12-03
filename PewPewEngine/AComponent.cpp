
#include "AComponent.h"

PewPewEngine::AComponent::AComponent()
{
}

PewPewEngine::AComponent::AComponent(int id)
{
	_id = std::to_string(id);
	//_shape.setRadius(radius);
	//_shape.setFillColor(sf::Color(r, g, b));
}

void PewPewEngine::AComponent::Awake()
{
}

void PewPewEngine::AComponent::Start()
{
}

void PewPewEngine::AComponent::Update(float deltaTime)
{
}

void PewPewEngine::AComponent::LateUpdate(float deltaTime)
{
}

std::string PewPewEngine::AComponent::GetID()
{
	return _id;
}

void PewPewEngine::AComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}
