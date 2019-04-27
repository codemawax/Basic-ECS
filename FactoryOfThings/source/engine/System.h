#pragma once

namespace EntityComponentSystem
{

class Entity;
class EntityManager;

class System
{
public:
    explicit System(EntityManager& entityManager);
    virtual ~System() = default;

    virtual void OnEntityCreated(const Entity& entity) = 0;
    virtual void OnEntityDestroyed(const Entity& entity) = 0;
    virtual void Update() = 0;

protected:
    EntityManager* entityManager;
};

}