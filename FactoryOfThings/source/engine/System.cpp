#include "System.h"

namespace EntityComponentSystem
{

System::System(EntityManager& entityManager) : entityManager{&entityManager}
{

}

}