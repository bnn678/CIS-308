int Min(int *vals, int size)
{
	int min = vals[0];
	int i;
	for (int i = 1; i < size; i++)
	{
		if (vals[i] < min)
		{
			min = vals[i];
		}
	}

	return min;
}

int Max(int *vals, int size)
{
	int max = vals[0];
	int i;
	for (i = 1; i < size; i++)
	{
		if (vals[i] > max)
		{
			max = vals[i];
		}
	}

	return max;
}

double avg(int *vals, int size)
{
	int sum = 0;
	int i;
	for (int i = 0; i < size; i++)
	{
		sum += vals[i];
	}

	return sum / (double)size;
}