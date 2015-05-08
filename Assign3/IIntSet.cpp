#include "IIntSet.h"
#include "UnionIntSet.h"
#include "BasicIntSet.h"

IIntSet::IIntSet() {};

IIntSet* IIntSet::Union(IIntSet &other)
{
	//return new UnionIntSet((BasicIntSet&)this, (IntervalIntSet&)other);

	return nullptr;
}