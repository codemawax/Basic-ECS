#pragma once

#include <Utils.h>
#include "Entity.h"

class World
{
public:
    void Update();
    void Draw();

private:
    vector<unique_ptr<Entity>> entities;
};