#pragma once

#include <engine/EntityManagerTypes.h>
#include <limits>

namespace EntityComponentSystem
{

using PoolIndex = unsigned long long;

class Component
{
public:
    Component();
    virtual ~Component() = default;
    virtual bool Init(/*data*/) = 0; //todo

private:
    void SetEntityID(EntityID id) { entityID = id; }
    EntityID GetEntityID() { return entityID; }

    void SetPoolIndex(PoolIndex index) { poolIndex = index; }
    PoolIndex GetPoolIndex() { return poolIndex; }

private:
    static constexpr PoolIndex INVALID_POOL_INDEX = std::numeric_limits<PoolIndex>::max();

    EntityID entityID;
    PoolIndex poolIndex;
};

}