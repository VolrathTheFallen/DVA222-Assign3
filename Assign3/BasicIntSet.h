
#ifndef BASICINTSET_H
#define BASICINTSET_H

#include "IIntSet.h"
#include <string>

class BasicIntSet : public IIntSet
{
private:
	int* data;

public:
	BasicIntSet();
	~BasicIntSet();

	bool Contains(int element);
	void Add(int toAdd);
	//void ToString(char *str, int max);
	void ToString(std::string &str);
	static int CompareInt(const void* l, const void* r);
	void SortBasicIntSet();
	int GetNumElements();
	int GetElementAtIndex(int index);

	IIntSet* Union(IIntSet &other);
};

#endif