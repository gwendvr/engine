#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace PewPewEngine
{
	class SpriteRenderer : public AComponent
	{
    protected:
        sf::Sprite _sprite;
        sf::Texture _texture;

    public:
        SpriteRenderer(AEntity* parent, int id);
        void Init(std::string path);
        void setSprite();
        void setColor(int r, int g, int b);
        void setSmooth(bool smooth);
        void setPosition(float x, float y);
        void setScale(float sizeX, float sizeY);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

