#include "IIntSet.h"

#include <iostream>

using namespace std;

void main()
{
	IIntSet *s1 = new BasicIntSet();
	s1->Add(10);
	s1->Add(12);

	IIntSet *s2 = new IntervalSet();
	s2->Add(20);
	s2->Add(21);
	s2->Add(22);
	s2->Add(100);
	s2->Add(101);
	s2->Add(102);

	IIntSet *s3;
	s3 = s1->Union(s2);


	cout << s3.ToString(); //char *, int max
}