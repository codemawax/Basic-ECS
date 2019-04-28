#pragma once

#include <unordered_map>

#include "BaseSystem.h"
#include "Component.h"
#include "Entity.h"
#include "EntityManagerTypes.h"

namespace EntityComponentSystem
{

class Entity;

template <class ... Components>
class System : private BaseSystem
{
protected:
    using ComponentTuple = std::tuple<std::add_pointer_t<Components>...>;
    std::vector<ComponentTuple> components;

public:
    void OnEntityCreated(const Entity& entity) override final;
    void OnEntityDestroyed(const Entity& entity) override final;

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
                components.emplace_back(std::move(std::move(componentTuple)));
                break; //we have found the matching components
            }
        }
    }
}

template <class ... Components>
void System<Components...>::OnEntityDestroyed(const Entity& entity)
{
    //todo: create map to find existing component tuple
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