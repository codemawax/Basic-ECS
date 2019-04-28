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

private:
    void SetEntityID(EntityID id) { entityID = id; }
    EntityID GetEntityID() { return entityID; }

private:
    EntityID entityID;

};

}