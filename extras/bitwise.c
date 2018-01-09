
void	neg_base_printer(long long num, int base, int int_size, int caps)
{
	char	output[64];
	int		bitmask;
	int		mask_width;
	int		x;
	int		count[2];

	x = 0;
	count[1] = 0;
	mask_width = (base == HEXA) ? 4 : 0;	
	if (base != HEXA)
		mask_width = (base == OCTAL) ? 3 : 1;	
	while (x < int_size)
	{
		bitmask = 0;
		count[0] = 0;	
			while (count[0] < mask_width)
			{
				if ((num & 1UL << x))
					bitmask ^= 1UL << count[0]; 
				count[0]++;
				x++;
			}
		output[count[1]++] = (caps) ? g_hexadec_uc[bitmask] : g_hexadec[bitmask];
	}
	ft_print_output(output, count[1], base);
}

