#pragma once

#include <Utils.h>
#include <engine/Component.h>
#include "Renderable.h"

class SpriteComponent : public Component, public Renderable
{
private:
    Image image;
};
