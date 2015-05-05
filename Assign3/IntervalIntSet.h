#include "IIntSet.h"
#include "structs.h"



class IntervalIntSet : public IIntSet
{
private:
	Interval* data;

public:
	IntervalIntSet();
	~IntervalIntSet();

	bool Contains(int element);
	void Add(int toAdd);
	void ToString(char *, int max);
};