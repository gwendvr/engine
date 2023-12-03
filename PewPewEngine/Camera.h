#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace PewPewEngine {
    class Camera : public AComponent
    {
    public:
        sf::View _view;
        Camera(AEntity* parent, int id);

        void InitView(float width, float height);
        void setZoom(float zoom);
        void setViewport(sf::FloatRect& viewport);
        void setRotation(float angle);
        void update();
    };
}