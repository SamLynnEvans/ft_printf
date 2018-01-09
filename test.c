#include <stdio.h>

int main()
{
	int a = 123;
	int b = -123;
	int x = 0;
	char bitsa[9] = "00000000";
	char bitsb[9] = "00000000";

	while (x < 8)
	{
		if (!(a & 1 << x))
			bitsa[7 - x] = '1';
		if (b & 1 << x)
			bitsb[7 - x] = '1';	
		x++;
	}
	printf("bits_a = %s\n", bitsa);
	printf("bits_b = %s\n", bitsb);
}
