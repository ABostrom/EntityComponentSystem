#include "EntityManager.h"

EntityHandle EntityManager::CreateEntity(const ArchetypeHandle& handle)
{
	//TODO: use the handle to create the Entity.


	Entities.push_back(std::make_shared<Entity>());
	return {static_cast<int>(Entities.size()) - 1};
}

std::shared_ptr<Entity> EntityManager::GetEntity(const EntityHandle& handle)
{
	return Entities[handle.index];
}

