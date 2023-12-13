// EntityComponentSystem.cpp : Defines the entry point for the application.
//

#include "EntityComponentSystem.h"

#include "Entity.h"
#include "EntityManager.h"
#include "ExecutionContext.h"
#include "Fragment.h"
#include "Processor.h"

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
	ArchetypeManager ArchetypeManager;
	const ArchetypeHandle bool_int_float_handle = ArchetypeManager.CreateArchetype<TestFragment_Bool, TestFragment_Int, TestFragment_Float>();
	const ArchetypeHandle int_float_handle = ArchetypeManager.CreateArchetype<TestFragment_Int, TestFragment_Float>();

	EntityManager EntityManager;
	std::vector<EntityHandle> handles;

	//create a bunch of entities.
	//TODO: build an entity from a set of fragments.
	handles.push_back(EntityManager.CreateEntity(bool_int_float_handle));
	handles.push_back(EntityManager.CreateEntity(bool_int_float_handle));
	handles.push_back(EntityManager.CreateEntity(int_float_handle));
	handles.push_back(EntityManager.CreateEntity(int_float_handle));

	//find entities from the manager.
	for (const EntityHandle& handle : handles)
	{
		const std::shared_ptr<Entity> found = EntityManager.GetEntity(handle);
		cout << "Entity:" << found << endl;
	}

	const std::vector<unique_ptr<Processor>> Processors = { make_unique<TestProcesser_BoolIntFloat>(), make_unique<TestProcesser_BoolIntFloat>() };
	for (const unique_ptr<Processor>& processor : Processors)
	{
		processor->ConfigureQueries();
	}

	//TODO: Loop here like a game loop.
	ExecutionContext context;
	for (const unique_ptr<Processor>& processor : Processors)
	{
		processor->Execute(EntityManager, context);
	}

	return 0;
}
