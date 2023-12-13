#pragma once
#include "EntityQuery.h"


class Processor
{
public:
	virtual ~Processor() = default;
	virtual void ConfigureQueries() = 0;
	virtual void Execute(class EntityManager& EntityManager, class ExecutionContext& Context) = 0;
};


class TestProcesser_IntFloat : public Processor
{
	EntityQuery Query;

public:
	void ConfigureQueries() override;
	void Execute(class EntityManager& EntityManager, class ExecutionContext& Context) override;
};


class TestProcesser_BoolIntFloat : public Processor
{
	EntityQuery Query;

public:
	void ConfigureQueries() override;
	void Execute(class EntityManager& EntityManager, class ExecutionContext& Context) override;
};