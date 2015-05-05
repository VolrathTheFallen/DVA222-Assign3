
#ifndef BASICINTSET_H
#define BASICINTSET_H

#include "IIntSet.h"


class BasicIntSet : public IIntSet
{
private:
	int* data;

public:
	BasicIntSet();
	~BasicIntSet();

	bool Contains(int element);
	void Add(int toAdd);
	void ToString(char *str, int max);
};

#endif