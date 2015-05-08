#include "IIntSet.h"
#include "IntervalIntSet.h"
#include "Interval.h"

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

IntervalIntSet::IntervalIntSet(IntervalIntSet& iSet)
{
	numElements = iSet.numElements;
	numIntervals = iSet.numIntervals;
	doubleHere = iSet.doubleHere;

	this->data = new Interval[numIntervals];

	for (int i = 0; i < numIntervals; i++)
	{
		data[i] = iSet.data[i];
	}
}

bool IntervalIntSet::Contains(int toFind)
{
	for (int i = 0; i < numIntervals; i++) 
	{
		if (toFind >= data[i].from && toFind <= data[i].to)
			return true;
	}

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
		return;
	} 
	else
	{
		// Loop through the array of Intervals and check how it shoiuld be added
		for (int i = 0; i < numIntervals; i++)
		{

			// if elem can merge two intervals into one bigger, do this
			if (toAdd == data[i].to + 1 && toAdd == data[i + 1].from - 1)
			{
				data[i].to = data[i + 1].to;
				numIntervals--;
				for (i; i < numIntervals - 2; i++) //TODO: Maybe not -2
				{
					data[i + 1] = data[i + 2];
				}
				return;
			}

			// if elem should increase or decrease any existing interval
			else if (toAdd == data[i].from - 1)
			{
				data[i].from--;
				return;
			}
			else if (toAdd == data[i].to + 1)
			{
				data[i].to++;
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

		SortIntervalSet(); //Sort after new Interval gets added
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


void IntervalIntSet::SortIntervalSet()
{
	qsort(data, numIntervals, sizeof(Interval), Interval::CompareInterval);
}

int IntervalIntSet::GetNumIntervals()
{
	return numIntervals;
}

Interval IntervalIntSet::GetIntervalAtIndex(int index)
{
	return data[index];
}