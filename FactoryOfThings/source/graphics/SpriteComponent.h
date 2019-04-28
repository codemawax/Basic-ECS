#pragma once

#include <functional>
#include <string>

#include <SFML/Graphics.hpp>

#include <engine/Component.h>

class SpriteComponent : public EntityComponentSystem::Component
{
public:
    static constexpr ComponentID ID = 0; //todo: hash class name

private:
    sf::Sprite sprite;

public:
    bool Init() override;

    const sf::Sprite& GetSprite() const { return sprite; }
};
