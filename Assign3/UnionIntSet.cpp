#include "UnionIntSet.h"
#include "structs.h"

#include <assert.h>
#include <stdlib.h>
#include <string>

UnionIntSet::UnionIntSet()
{
	data = new Interval(0,0);

	numElements = 0;
	doubleHere = 2;

	assert(data);
}

UnionIntSet::~UnionIntSet()
{
	delete(data);
}

bool UnionIntSet::Contains(int element)
{

	return false;
}

void UnionIntSet::Add(int toAdd)
{


	assert(data);
}

void UnionIntSet::ToString(std::string &str)
{

}