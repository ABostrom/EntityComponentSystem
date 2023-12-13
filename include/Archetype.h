#pragma once

#include <set>
#include <typeinfo>
#include <typeindex>


//Archetypes are unique sets of fragments
//they serve as a template for building entities of that archetype.

struct Archetype
{
	Archetype() = default;

	void SetFragments() {}

	template <typename T, typename ... Args>
	void SetFragments()
	{
		FragmentSet.insert(std::type_index(typeid(T)));

		SetFragments<Args...>();
	}


private:
	std::set<std::type_index> FragmentSet;
};


