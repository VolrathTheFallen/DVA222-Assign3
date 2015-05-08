#include "BasicIntSet.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sstream>
#include <iostream>

#include "UnionIntSet.h"

BasicIntSet::BasicIntSet()
{
	data = new int[2];
	assert(data);

	numElements = 0;
	doubleHere = 2;
}

BasicIntSet::~BasicIntSet()
{
	delete(data);
}

bool BasicIntSet::Contains(int toFind)
{
	for (int i = 0; i < numElements; i++)
	{
		if (data[i] == toFind)
			return true;
	}

	return false;
}

void BasicIntSet::Add(int toAdd)
{
	if (Contains(toAdd))
		return;

	numElements++;

	if (numElements == doubleHere)
	{
		data = (int*)realloc(data, (sizeof(int)*numElements)*doubleHere);
		assert(data);
		doubleHere *= 2;
	}
	
	data[numElements-1] = toAdd; //TODO: check whether it's better to keep as sorted array, costly to sort, or unsorted, costly to search through

	SortBasicIntSet();
}


void BasicIntSet::ToString(std::string &str)
{
	std::string temp;

	for (int i = 0; i < numElements; i++)
	{
		temp = std::to_string(data[i]);
		str += temp;
		str += " ";
	}
}

int BasicIntSet::CompareInt(const void* l, const void* r)
{
	return (*(int*)l - *(int*)r);

	/*const int* _l = reinterpret_cast<const int*>(l);
	const int* _r = reinterpret_cast<const int*>(r);

	return _l < _r ? -1 : _l > _r ? 1 : 0;*/
}

void BasicIntSet::SortBasicIntSet()
{
	qsort(data, numElements, sizeof(int), CompareInt);
}

int BasicIntSet::GetNumElements()
{
	return numElements;
}

int BasicIntSet::GetElementAtIndex(int index)
{
	return data[index];
}

IIntSet* BasicIntSet::Union(IIntSet &other)
{
	return new UnionIntSet(*this, (IntervalIntSet&)other); //Probably doesnt work, should die when scope ends right?
}


/*
void BasicIntSet::ToString(char *str, int max)
{
	int counter = 0;
	char* temp;

	//Converts int to string
	for (int i = 0; i < numElements; i++)
	{
		int charsInInt = (int)((ceil(log10((float)data[i])) + 1)*sizeof(char));
		
		counter += charsInInt;

		if (counter > max)
			return;	//TODO: Throw

		temp = new char[charsInInt+1]; //num chars calculated by: (int)((ceil(log10(num)) + 1)*sizeof(char))

		std::cout << charsInInt << std::endl << temp << std::endl << max << std::endl << counter;

		sprintf_s(temp, max, "%d", data[i]);

		strcat_s(str, max, temp);
		delete(temp);
	}
}
*/