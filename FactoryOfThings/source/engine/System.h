#pragma once

#include <assert.h>
#include <unordered_map>

#include "BaseSystem.h"
#include "Component.h"
#include "Entity.h"

namespace EntityComponentSystem
{

template <class ... Components>
class System : private BaseSystem
{
    using EntityIDToComponentIndexMap = std::unordered_map<EntityID, size_t>;
    EntityIDToComponentIndexMap entityIDToComponentIndexMap;
protected:
    using ComponentTuple = std::tuple<std::add_pointer_t<Components>...>;
    std::vector<ComponentTuple> components;

public:
    void OnEntityCreated(const Entity& entity) override final;
    void OnEntityDestroyed(const EntityID entityID) override final;

private:
    template <size_t Index, class ComponentType, class ... ComponentArgs>
    bool ProcessComponent(ComponentID componentID, Component* component, ComponentTuple& resultComponentTuple);

    template <size_t Index>
    bool ProcessComponent(ComponentID componentID, Component* component, ComponentTuple& resultComponentTuple);

};

template <class ... Components>
void System<Components...>::OnEntityCreated(const Entity& entity)
{
    ComponentTuple resultComponentTuple;
    size_t matchingComponents{};
    for (auto& componentTuple : entity.GetComponents())
    {
        if (ProcessComponent<0, Components...>(componentTuple.first, componentTuple.second, resultComponentTuple))
        {
            ++matchingComponents;
            if (matchingComponents == sizeof...(Components))
            {
                components.emplace_back(std::move(componentTuple));
                entityIDToComponentIndexMap.emplace(entity.GetID(), components.size() - 1);
                break; // We have found the matching components
            }
        }
    }
}

template <class ... Components>
void System<Components...>::OnEntityDestroyed(const EntityID entityID)
{
    const auto findIt = entityIDToComponentIndexMap.find(entityID);

    if (findIt != entityIDToComponentIndexMap.end())
    {
        // Overwrite destroyed entity's components with the last component of the list
        components[findIt->second] = std::move(components.back());
        components.pop_back();

        // Retrieve a component from the moved tuple
        const auto* movedComponent = std::get<0>(components[findIt->second]);

        // Update the index
        auto movedTupleIt = entityIDToComponentIndexMap.find(movedComponent->GetEntityID());
        assert(movedTupleIt != entityIDToComponentIndexMap.end());
        movedTupleIt->second = findIt->second;
    }
}

template <class ... Components>
template<size_t Index, class ComponentType, class ... ComponentArgs>
bool System<Components...>::ProcessComponent(ComponentID componentID, Component* component, ComponentTuple& resultComponentTuple)
{
    if (ComponentType::ID == componentID)
    {
        std::get<Index>(resultComponentTuple) = static_cast<ComponentType*>(component);
        return true;
    }
    else
    {
        return ProcessComponent<Index + 1, ComponentArgs...>(componentID, component, resultComponentTuple);
    }
}

template <class ... Components>
template<size_t Index>
bool System<Components...>::ProcessComponent(ComponentID componentID, Component* component, ComponentTuple& resultComponentTuple)
{
    return false; //no more components to check
}

}