
#ifndef INTERVALINTSET_H
#define INTERVALINTSET_H


#include "IIntSet.h"
#include "structs.h"
#include <string>

class IntervalIntSet : public IIntSet
{
private:
	Interval* data;
	int numIntervals;

public:
	IntervalIntSet();
	~IntervalIntSet();

	bool Contains(int element);
	void Add(int toAdd);
	//void ToString(char *str, int max);
	void ToString(std::string &str);
};

#endif
