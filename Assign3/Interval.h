#ifndef INTERVAL_H
#define INTERVAL_H



class Interval
{
public:
	int from;
	int to;

	Interval();
	Interval(int from, int to);
	static int CompareInterval(const void* l, const void* r);
};

#endif