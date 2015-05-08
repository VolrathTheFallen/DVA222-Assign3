#include "IIntSet.h"
#include "BasicIntSet.h"
#include "IntervalIntSet.h"

#include <iostream>
#include <string>

using namespace std;

//#define MAX_STRING_SIZE 255



void main()
{
	//char *str = new char[MAX_STRING_SIZE];
	string str;
	string str2;
	string str3;

	IIntSet *s1 = new BasicIntSet();
	s1->Add(10);
	s1->Add(12);
	s1->Add(11);

	IntervalIntSet *s2 = new IntervalIntSet();
	s2->Add(20);
	s2->Add(21);
	s2->Add(22);
	s2->Add(100);
	s2->Add(101);
	s2->Add(102);
	s2->Add(105);
	s2->Add(106);
	s2->Add(108);
	s2->Add(109);
	s2->Add(107);
	s2->Add(3);
	s2->Add(4);
	s2->Add(5);

	IIntSet *s3;
	s3 = s1->Union(*s2); //Unclear who should free memory since returns pointer. Oh and is this shallow or deep?


	//cout << s3.ToString(*str, MAX_STRING_SIZE); //char *, int max
	//s1->ToString(str, MAX_STRING_SIZE);

	s1->ToString(str);
	s2->ToString(str2);
	s3->ToString(str3);

	cout << str << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	delete(s1); //Will this call destructor?
	delete(s2);
	delete(s3);

	system("pause");
}