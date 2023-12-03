#include "Application.h"
#include "AEntity.h"


PewPewEngine::AEntity::AEntity(std::string name, int id, PewPewEngine::Application* app)
{
	_name = name;
	_id = id;
	_app = app;
}

void PewPewEngine::AEntity::Awake()
{

}

void PewPewEngine::AEntity::Start()
{

}

void PewPewEngine::AEntity::Update(float deltaTime)
{
	for (int i = 0; i < _app->_components.size(); i++)
	{
		_app->_components[i]->Update(deltaTime);
	}
}

void PewPewEngine::AEntity::LateUpdate(float deltaTime)
{
	for (int i = 0; i < _app->_components.size(); i++)
	{
		_app->_components[i]->LateUpdate(deltaTime);
	}
}

void PewPewEngine::AEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(getTransform());
	for (int i = 0; i < _app->_components.size(); i++)
	{
		if (_app->_linkBetweenComponentAndEntity[_app->_components[i]->GetID()] == const_cast<AEntity*>(this)->GetID()) {
			target.draw(*(_app->_components[i]), states);
		}
	}
}

std::string PewPewEngine::AEntity::GetID()
{
	return _id;
}

std::string PewPewEngine::AEntity::GetName()
{
	return _name;
}
