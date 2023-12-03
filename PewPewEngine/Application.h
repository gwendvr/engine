#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "AEntity.h"
#include "AComponent.h"
#include "physics.h"

namespace PewPewEngine {
	class Application
	{
	protected:
		std::vector<AEntity*> _entities;

		int indexE = 0; //index entity
		int indexC = 0; //index components

	public:
		PewPewEngine::Physics physic;
		sf::RenderWindow _window;
		std::vector<AComponent*> _components;
		std::map<std::string, std::string> _linkBetweenComponentAndEntity;

		Application();
		~Application();

		void Init(int windowSizeX, int windowSizeY, std::string windowName);
		void Loop(Application* app);

		template<typename T>
		inline T* CreateEntities(std::string name)
		{
			T* entity = new T(name, indexE, this);
			_entities.push_back(entity);
			std::cout << "the entity : " << name << " was created with the id : " << indexE << std::endl;
			
			indexE++;
			return entity;
		}

		template<typename T>
		inline T* CreateComponentsAndAttachToEntity(AEntity* parent)
		{
			T* component = new T(parent, indexC);
			_components.push_back(component);
			_linkBetweenComponentAndEntity[component->GetID()] = parent->GetID(); //link components to entity parent
			std::cout << "the component : " << indexC << " was link to the entity : " << parent->GetName() << std::endl;

			indexC++;
			return component;
		}
	};
}

