



typedef struct Interval
{
	int from;
	int to;

	Interval(int from, int to)
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
}Interval;