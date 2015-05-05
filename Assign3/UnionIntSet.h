#include "IIntSet.h"
#include "structs.h"


class UnionIntSet : public IIntSet
{
private:
	Interval* data //union

public:
	UnionIntSet();
	~UnionIntSet();

	bool Contains(int element);
	void Add(int toAdd);
	void ToString(char *, int max);
};