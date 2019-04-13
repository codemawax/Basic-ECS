#pragma once

#include <Utils.h>

class Entity;
class System;

class EntityManager
{
public:
    void Update();
    void Draw();

    Entity& CreateEntity();

    void RegisterEntity(const Entity& entity);
    void UnregisterEntity(const Entity& entity);

private:
    vector<unique_ptr<Entity>> entities;
    vector<unique_ptr<System>> systems;
};