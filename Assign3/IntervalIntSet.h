
#ifndef INTERVALINTSET_H
#define INTERVALINTSET_H


#include "IIntSet.h"
#include "Interval.h"
#include <string>

class IntervalIntSet : public IIntSet
{
private:
	Interval* data;

protected:
	int numIntervals;

public:
	IntervalIntSet();
	IntervalIntSet(IntervalIntSet& iSet);
	~IntervalIntSet();

	int GetNumIntervals();
	Interval GetIntervalAtIndex(int index);
	bool Contains(int element);
	void Add(int toAdd);
	//void ToString(char *str, int max);
	void ToString(std::string &str);
	void SortIntervalSet();
};

#endif
