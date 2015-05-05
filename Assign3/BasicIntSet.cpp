#include "BasicIntSet.h"
#include <stdlib.h>
#include <assert.h>

BasicIntSet::BasicIntSet()
{
	data = new int[2];
	assert(data);

	numElements = 0;
	doubleHere = 2;
}

BasicIntSet::~BasicIntSet()
{
	delete(data);
}

bool BasicIntSet::Contains(int toFind)
{
	for (int i = 0; i < numElements; i++)
	{
		if (data[i] == toFind)
			return true;
	}

	return false;
}

void BasicIntSet::Add(int toAdd)
{
	if (Contains(toAdd))
		return;

	numElements++;

	if (numElements == doubleHere)
	{
		data = (int*)realloc(data, (sizeof(int)*numElements)*doubleHere);
		assert(data);
		doubleHere *= 2;
	}
	
	data[numElements-1] = toAdd; //TODO: check whether it's better to keep as sorted array, costly to sort, or unsorted, costly to search through
}

void BasicIntSet::ToString(char *str, int max)
{
	//TODO: do without string class and string stream
}