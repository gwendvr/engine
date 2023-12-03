#include "SpriteRenderer.h"

PewPewEngine::SpriteRenderer::SpriteRenderer(AEntity* parent, int id) : AComponent(id)
{
    _parent = parent;
}

void PewPewEngine::SpriteRenderer::Init(std::string path)
{
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(0.f, 0.f);
    setSmooth(true);
}

void PewPewEngine::SpriteRenderer::setSprite()
{
    _sprite.setTexture(_texture);
}

void PewPewEngine::SpriteRenderer::setColor(int r, int g, int b)
{
    _sprite.setColor(sf::Color(r, g, b));
}

void PewPewEngine::SpriteRenderer::setSmooth(bool smooth)
{
    _texture.setSmooth(smooth);
}

void PewPewEngine::SpriteRenderer::setPosition(float x, float y)
{
    _sprite.setPosition(x, y);
}

void PewPewEngine::SpriteRenderer::setScale(float sizeX, float sizeY)
{
    _sprite.setScale(sizeX, sizeY);
}

void PewPewEngine::SpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);

}