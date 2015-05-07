#include "UnionIntSet.h"
#include "Interval.h"

#include <assert.h>
#include <stdlib.h>
#include <string>

UnionIntSet::UnionIntSet()
{
	data = new Interval(0,0);

	numElements = 0;
	numIntervals = 0;
	doubleHere = 2;

	assert(data);
}

UnionIntSet::~UnionIntSet()
{
	delete(data);
}

bool UnionIntSet::Contains(int toFind)
{
	for (int i = 0; i < numIntervals; i++)
	{
		if (toFind >= data[i].from && toFind <= data[i].to)
			return true;
	}

	return false;
}

void UnionIntSet::Add(int toAdd)
{


	assert(data);
}

void UnionIntSet::ToString(std::string &str)
{

}