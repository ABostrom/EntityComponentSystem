// EntityComponentSystem.cpp : Defines the entry point for the application.
//

#include "EntityComponentSystem.h"

#include "Entity.h"
#include "EntityManager.h"
#include "Fragment.h"

using namespace std;


/*
TODO:
- EntityManager
- Entity Spawner
	- EntityConfigAsset - don't think this is needed. Can just make them via the constructor for the time being.
		- Builder / Factory pattern?
		- Traits / Set of Fragments
- Processors
	- do work on a set of entities with the specified fragments
- ExecutionContext
	- GetFragmentView
	- GetMutableFragmentView
	- ForEachEntity

- Queries
	- Processors can have a set of requirements / dependencies in order to process an entity
	- Register a Processor with a Query
	

- Fragments
	- SharedFragments
	- SpecalisedFragments
		- VelocityFragment
		- TransformFragment

- Long Term additions
	- Observers
		- consider this one - not sure if i need to go this deep.
	
*/

int main()
{
	//create entities.
	EntityManager EntityManager;
	std::vector<EntityHandle> handles;

	//create a bunch of entities.
	//TODO: build an entity from a set of fragments.
	handles.push_back(EntityManager.CreateEntity());
	handles.push_back(EntityManager.CreateEntity());
	handles.push_back(EntityManager.CreateEntity());
	handles.push_back(EntityManager.CreateEntity());

	//find entities from the manager.
	for (const EntityHandle& handle : handles)
	{
		const std::shared_ptr<Entity> found = EntityManager.GetEntity(handle);
		cout << "Entity:" << found << endl;
	}

	return 0;
}
