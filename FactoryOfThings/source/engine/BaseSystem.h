#pragma once

namespace EntityComponentSystem
{

class Entity;
class EntityManager;

class BaseSystem
{
public:
    explicit BaseSystem(EntityManager& entityManager);
    virtual ~BaseSystem() = default;

    virtual void OnEntityCreated(const Entity& entity) = 0;
    virtual void OnEntityDestroyed(const Entity& entity) = 0;
    virtual void Update() = 0;

protected:
    EntityManager * entityManager;
};

}