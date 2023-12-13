#pragma once


//Data Only Structs that entities can own, and processors can query on.
struct Fragment
{
	Fragment() = default;
};

struct TestFragment_Bool : public Fragment
{
	TestFragment_Bool() = default;
	bool Value;
};

struct TestFragment_Int : public Fragment
{
	TestFragment_Int() = default;
	int Value;
};

struct TestFragment_Float : public Fragment
{
	TestFragment_Float() = default;
	float Value;
};