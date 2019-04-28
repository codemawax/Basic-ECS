#include "RenderSystem.h"

void RenderSystem::Update()
{
    for (ComponentTuple& componentTuple : components)
    {
        SpriteComponent* spriteComponent{ std::get<SpriteComponent*>(componentTuple) };
        const sf::Sprite& sprite{ spriteComponent->GetSprite() };
        sf::RenderWindow window;
        window.draw(sprite);
    }
}
