#pragma once

#include <vector>
#include <memory>

#include "ArchetypeManager.h"
#include "Archetype.h"
#include "Entity.h"


struct EntityHandle
{
	EntityHandle() = default;
	EntityHandle(int _index) : index(_index) {}

	bool IsSet() const { return index >= 0; }
	// bool IsValid() const { return index >= 0; }
	void Reset() { index = -1; }

	bool operator==(const EntityHandle& Other) const { return index == Other.index; }
	bool operator!=(const EntityHandle& Other) const { return index != Other.index; }

	int index = -1;
};


class EntityManager
{
public:

	EntityManager() = default;
	EntityHandle CreateEntity(const ArchetypeHandle& handle);
	std::shared_ptr<Entity> GetEntity(const EntityHandle& handle);

private:
	std::vector<std::shared_ptr<Entity>> Entities;
};
