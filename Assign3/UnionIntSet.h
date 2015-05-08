
#ifndef UNIONINTSET_H
#define UNIONINTSET_H

#include "IIntSet.h"
#include "Interval.h"
#include "BasicIntSet.h"
#include "IntervalIntSet.h"

class UnionIntSet : public IntervalIntSet
{
private:
	/*Interval* data; //union
	int numIntervals;*/

public:
	UnionIntSet(BasicIntSet& bSet, IntervalIntSet& iSet);
	UnionIntSet(IntervalIntSet& iSet, BasicIntSet& bSet);
	UnionIntSet(BasicIntSet& l, BasicIntSet& r);
	UnionIntSet(IntervalIntSet& l, IntervalIntSet& r);
	//~UnionIntSet();

	/*bool Contains(int element);
	void Add(int toAdd);
	//void ToString(char *str, int max);
	void ToString(std::string &str);*/
};

#endif
