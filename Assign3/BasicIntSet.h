#include "IIntSet.h"



class BasicIntSet : public IIntSet
{
private:
	int* data;
	int numElements;

public:
	BasicIntSet();
	~BasicIntSet();

	bool Contains(int element);
	void Add(int toAdd);
	void ToString(char *, int max);
};