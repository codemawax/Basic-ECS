#pragma once

#include <vector>
#include <unordered_map>

#include "BaseSystem.h"
#include "Component.h"
#include "Entity.h"
#include "EntityManagerTypes.h"
#include "NonCopyable.h"

namespace EntityComponentSystem
{

class EntityManager : private EntityComponentSystem::NonCopyable
{
public:
    EntityManager();
    ~EntityManager();

    void CreateSystems();
    void Update();

    EntityID CreateEntity();
    void DestroyEntity();

private:
    using Entities = std::unordered_map<EntityID, Entity>;
    using Components = std::vector<std::vector<Component*>>;
    using Systems = std::vector<BaseSystem>;

    Entities entities;
    Components components;
    Systems systems;
};

}