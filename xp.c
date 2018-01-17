#include <unistd.h>

int main()
{
	//char happy[] = {0xe2, 0x98, 0xba};
	char happy[] = {226, 152, 186, 65};
	unsigned char a[4];

	a[0] = 226;
	a[1] = 152;	
	a[2] = 186;	
	a[3] = 65;	
	write(1, a, 3);
}
