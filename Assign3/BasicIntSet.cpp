#include "BasicIntSet.h"

#include <stdlib.h>
#include <assert.h>

BasicIntSet::BasicIntSet()
{
	data = new int;

	numElements = 0;
	doubleHere = 2;

	assert(data);
}

BasicIntSet::~BasicIntSet()
{
	delete(data);
}

bool BasicIntSet::Contains(int toFind)
{

}

void BasicIntSet::Add(int toAdd)
{
	if (Contains(toAdd))
		return;

	if (numElements == doubleHere)
	{
		data = (int*)realloc(data, (sizeof(int)*numElements)*doubleHere);
		doubleHere *= 2;
	}

	assert(data);

	data[sizeof(data) / sizeof(int)] = toAdd;
}

void BasicIntSet::ToString(char *, int max)
{

}