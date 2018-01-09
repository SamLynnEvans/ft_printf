int	get_num_length(long long num, int base)
{
	int count;

	count = 0;
	while (num)
	{
		num /= base;
		count++;
	}
	return ((count == 0) ? 1 : count);
}
