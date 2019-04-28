#pragma once

#include <engine/EntityManagerTypes.h>
#include <limits>

namespace EntityComponentSystem
{

class Component
{
public:
    Component();
    virtual ~Component() = default;
    virtual bool Init(/*data*/) = 0; //todo

    EntityID GetEntityID() const { return entityID; }
    void SetEntityID(EntityID id) { entityID = id; }

private:
    EntityID entityID;
};

}