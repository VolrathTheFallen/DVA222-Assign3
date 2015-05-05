#include "IntervalIntSet.h"
#include "structs.h"

#include <stdlib.h>
#include <assert.h>

IntervalIntSet::IntervalIntSet()
{
	data = new Interval(0, 0);

	numElements = 0;
	doubleHere = 2;

	assert(data);
}

IntervalIntSet::~IntervalIntSet()
{
	delete(data);
}

bool IntervalIntSet::Contains(int element)
{

}

void IntervalIntSet::Add(int toAdd)
{

	assert(data);
}

void IntervalIntSet::ToString(char *, int max)
{

}