#pragma once

#include <engine/System.h>

#include "SpriteComponent.h"

class RenderSystem : public EntityComponentSystem::System<SpriteComponent>
{
    void Update() override;
};