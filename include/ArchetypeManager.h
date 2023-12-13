#pragma once
#include <memory>
#include <vector>
#include "Archetype.h"


struct ArchetypeHandle
{
	int index;
};

//this contains the unique set of different Archtypes we can have.
class ArchetypeManager
{

public:

	template <typename ... Args>
	ArchetypeHandle CreateArchetype()
	{
		Archetype archetype;
		archetype.SetFragments<Args...>();
		Archetypes.push_back(archetype);
		return { static_cast<int>(Archetypes.size()) - 1 };
	}

private:
	std::vector<Archetype> Archetypes;
};


