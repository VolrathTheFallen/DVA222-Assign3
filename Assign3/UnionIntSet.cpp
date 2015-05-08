#include "UnionIntSet.h"
#include "BasicIntSet.h"
#include "IntervalIntSet.h"
#include "Interval.h"

#include <assert.h>
#include <stdlib.h>
#include <string>

/* UnionIntSet::UnionIntSet()
{
	data = new Interval(0,0);

	numElements = 0;
	numIntervals = 0;
	doubleHere = 2;

	assert(data);
} */

UnionIntSet::UnionIntSet(BasicIntSet& bSet, IntervalIntSet& iSet) 
	:IntervalIntSet(iSet)
{
	for (int i = 0; i < bSet.GetNumElements(); i++)
		Add(bSet.GetElementAtIndex(i));
}

UnionIntSet::UnionIntSet(IntervalIntSet& iSet, BasicIntSet& bSet) //TODO: How do I merge this and the one above?
	:IntervalIntSet(iSet)
{
	for (int i = 0; i < bSet.GetNumElements(); i++)
		Add(bSet.GetElementAtIndex(i));

}

UnionIntSet::UnionIntSet(BasicIntSet& l, BasicIntSet& r) //Should call default constructor from IntervalIntSet parent
{
	for (int i = 0; i < l.GetNumElements(); i++)
		Add(l.GetElementAtIndex(i));
	for (int i = 0; i < r.GetNumElements(); i++)
		Add(r.GetElementAtIndex(i));
}

UnionIntSet::UnionIntSet(IntervalIntSet& l, IntervalIntSet& r)
	:IntervalIntSet(l)
{
	for (int i = 0; i < r.GetNumIntervals(); i++)	//Loop through Array of Intervals
	{
		for (int j = 0; j < r.GetIntervalAtIndex(i).to - r.GetIntervalAtIndex(i).from || j == 0; j++)	//Loop through each Interval and attempt to add each value
			Add(r.GetIntervalAtIndex(i).from + j);
	}
}

/*
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

}*/