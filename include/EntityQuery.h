#pragma once

#include <functional>
#include <set>
#include <typeindex>

#include "EntityManager.h"
#include "Processor.h"

class Processor;
class ExecutionContext;



class EntityQuery 
{
public:

	template <typename T>
	void AddRequirement()
	{
		Requirements.insert(std::type_index(typeid(T)));
	}


	void ForAllEntity(const EntityManager& EntityManager, const ExecutionContext& Context, const std::function<void(const ExecutionContext&)>& Func);
	void RegisterWithProcessor(const Processor& Processor);

private:

	std::set<std::type_index> Requirements;
};


