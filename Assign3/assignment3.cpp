#include "IIntSet.h"
#include "BasicIntSet.h"
#include "IntervalIntSet.h"

#include <iostream>
#include <string>

using namespace std;

#define MAX_STRING_SIZE 255



void main()
{
	//char *str = new char[MAX_STRING_SIZE];
	string str;
	string str2;

	IIntSet *s1 = new BasicIntSet();
	s1->Add(10);
	s1->Add(12);

	IIntSet *s2 = new IntervalIntSet();
	s2->Add(20);
	s2->Add(21);
	s2->Add(22);
	s2->Add(100);
	s2->Add(101);
	s2->Add(102);

	//IIntSet *s3;
	//s3 = s1->Union(s2);


	//cout << s3.ToString(*str, MAX_STRING_SIZE); //char *, int max
	//s1->ToString(str, MAX_STRING_SIZE);
	s1->ToString(str);
	s2->ToString(str2);

	cout << str << endl;
	cout << endl << str2;

	system("pause");

	//delete(str);
}