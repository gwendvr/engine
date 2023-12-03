#include <iostream>
#include <map>
#include <SFML/Window.hpp>
#include "Application.h"

PewPewEngine::Application::Application()
{
    std::cout << "App open" << std::endl;
}

PewPewEngine::Application::~Application()
{
    std::cout << "App close" << std::endl;
}

void PewPewEngine::Application::Init(int windowSizeX, int windowSizeY, std::string windowName)
{
    std::cout << "App init" << std::endl;
    _window.create(sf::VideoMode(windowSizeX, windowSizeY), windowName);
}

void PewPewEngine::Application::Loop(Application* app)
{
    sf::Clock clock;

    while (_window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        _window.clear();

        for (int i = 0; i < _entities.size(); i++)
        {
            _entities[i]->Update(deltaTime);
        }

        physic.Update(deltaTime, app);

        for (int i = 0; i < _entities.size(); i++)
        {
            _entities[i]->LateUpdate(deltaTime);
        }

        for (int i = 0; i < _entities.size(); i++)
        {
            _window.draw(*_entities[i]);
        }

        _window.display();
    }
}