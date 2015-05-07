#include "IIntSet.h"
#include "IntervalIntSet.h"
#include "structs.h"

#include <stdlib.h>
#include <assert.h>
#include <string>

IntervalIntSet::IntervalIntSet()
{
	data = new Interval[2];

	numElements = 0;
	numIntervals = 0;
	doubleHere = 2;

	assert(data);
}

IntervalIntSet::~IntervalIntSet()
{
	delete(data); //TODO: Might need to loop through and delete each interval
}

bool IntervalIntSet::Contains(int toFind)
{
	for (int i = 0; i < numIntervals; i++) 
	{
		if (toFind >= data[i].from && toFind <= data[i].to)
			return true;
	}
	/*int nInInterval;

	for (int i = 0; i < numElements; i++)
	{
		nInInterval = data[i].from - data[i].to;

		for (int j = 0; j < nInInterval; j++)
		{ 
			if (data[i].from + j == toFind)
				return true;
		}
	}*/

	return false;
}

void IntervalIntSet::Add(int toAdd)
{
	if (Contains(toAdd))
		return;

	numElements++;

	if (numIntervals == 0) 
	{
		data[0].from = toAdd;
		data[0].to = toAdd;
		numIntervals++;
	} 
	else
	{

		// Loop through the array of Intervals , and check each Interval if 'elem' could be added, if not, create new Interval on next index in array
		for (int i = 0; i <= numIntervals; i++) 
		{
			if (toAdd == data[i].from - 1) 
			{
				data[i].from--; // = toAdd;
				return;
			}
			else if (toAdd == data[i].to + 1) 
			{
				data[i].to++; // = toAdd;
				return;
			}
		}

		// If new elem didn't belong to any existing intervals, start a new one on the next free index
		data[numIntervals] = Interval(toAdd, toAdd); //TODO: Will this be on the heap?
		numIntervals++;

		if (numIntervals == doubleHere)
		{
			data = (Interval*)realloc(data, (sizeof(Interval)*numIntervals)*doubleHere);
			assert(data);
			doubleHere *= 2;
		}
	}
}

void IntervalIntSet::ToString(std::string &str)
{
	std::string temp;

	for (int i = 0; i < numIntervals; i++)
	{
		temp = std::to_string(data[i].from);
		str += "[";
		str += temp;
		str += "..";
		temp = std::to_string(data[i].to);
		str += temp;
		str += "] ";
	}
}
