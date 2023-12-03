#include "Camera.h"
#include "AEntity.h"
#include "Application.h";

PewPewEngine::Camera::Camera(AEntity* parent, int id) : AComponent(id)
{
    _parent = parent;
}

void PewPewEngine::Camera::InitView(float width, float height)
{
    _view.setSize(width, height);
}

void PewPewEngine::Camera::setZoom(float zoom)
{
    _view.zoom(zoom);
}

void PewPewEngine::Camera::setViewport(sf::FloatRect& viewport)
{
    _view.setViewport(viewport);
}

void PewPewEngine::Camera::setRotation(float angle)
{
    _view.setRotation(angle);
}

void PewPewEngine::Camera::update()
{
    _view.setCenter(_parent->transform.getPosition());
}
