#include "Interval.h"

Interval::Interval()
{
	from = 0;
	to = 0;
}

Interval::Interval(int from, int to)
{
	if (from < to)
	{
		this->from = from;
		this->to = to;
	}
	else
	{
		this->from = to;
		this->to = from;
	}
}

int Interval::CompareInterval(const void* l, const void* r)
{
	const Interval* _l = reinterpret_cast<const Interval*>(l);
	const Interval* _r = reinterpret_cast<const Interval*>(r);
	return _l->from < _r->from ? -1 : _l->from > _r->from ? 1 : 0;
}