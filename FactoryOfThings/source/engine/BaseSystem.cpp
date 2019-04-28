#include "BaseSystem.h"

#include "Entity.h"
#include "EntityManager.h"

namespace EntityComponentSystem
{

BaseSystem::BaseSystem(EntityManager& entityManager) : entityManager{ &entityManager }
{

}

}