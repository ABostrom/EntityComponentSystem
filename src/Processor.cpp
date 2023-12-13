#include "Processor.h"
#include "EntityManager.h"
#include "EntityQuery.h"
#include "Fragment.h"

void TestProcesser_IntFloat::ConfigureQueries()
{
	Query.AddRequirement<TestFragment_Int>();
	Query.AddRequirement<TestFragment_Float>();

	Query.RegisterWithProcessor(*this);
}

void TestProcesser_IntFloat::Execute(EntityManager& EntityManager, ExecutionContext& Context)
{
	//TODO: do some ops on all the entities in our context.
	Query.ForAllEntity(EntityManager, Context, [](const ExecutionContext& Context)
	{

	});

}

void TestProcesser_BoolIntFloat::ConfigureQueries()
{
	Query.AddRequirement<TestFragment_Bool>();
	Query.AddRequirement<TestFragment_Int>();
	Query.AddRequirement<TestFragment_Float>();

	Query.RegisterWithProcessor(*this);
}

void TestProcesser_BoolIntFloat::Execute(EntityManager& EntityManager, ExecutionContext& Context)
{
	//TODO: do some ops on all the entities in our context.
	Query.ForAllEntity(EntityManager, Context, [](const ExecutionContext& Context)
	{

	});
}
