#include "EntityQuery.h"

#include <typeindex>

#include "ExecutionContext.h"
#include <typeinfo>

template <typename T>
void EntityQuery::AddRequirement()
{
	Requirements.insert(std::type_index(typeid(T)));
}


void EntityQuery::RegisterWithProcessor(const Processor& Processor)
{

}

void EntityQuery::ForAllEntity(const EntityManager& EntityManager, const ExecutionContext& Context,const std::function<void(const ExecutionContext&)>& Func)
{
	//Do some processing on query information to find the subset of entities to process as a set of entities
	//for each entity
		//ammend or do some processing on the context /pack them into the context to feed to the query.

		//call the lambda function on the updated context.
		Func(Context);
}
