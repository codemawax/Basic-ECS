#pragma once

#include <assert.h>
#include <unordered_map>

#include "Component.h"
#include "EntityManagerTypes.h"
#include "NonCopyable.h"

namespace EntityComponentSystem
{

class Entity : private NonCopyable
{
    using ComponentMap = std::unordered_map<ComponentID, Component*>;

    EntityID id;
    ComponentMap components;

public:
    explicit Entity(EntityID id) : id{id} {}

    EntityID GetID() const { return id; }

    void AddComponent(ComponentID componentID, Component* component)
    {
        assert(components.find(componentID) == components.end()); // No duplicate components
        components.emplace(componentID, component);
    }

    template<class ComponentType>
    ComponentType* GetComponent() const;

    const ComponentMap& GetComponents() const { return components; }
};

template<class ComponentType>
ComponentType* Entity::GetComponent() const
{
    auto findIt = components.find(ComponentType::ID);
    if (findIt != components.end())
    {
        return findIt->second;
    }
    return nullptr;
}

}