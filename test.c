#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char happy[] = { 0xe2, 0x98, 0xba };

int main()
{

		int i = 0;
	   write(1, happy, 3);
	   
	   irintf("\n%s", happy);
rintf("\n%lc", (wchar_t)happy);
	   while (happy[i])
		   i++;
	   printf("\n%d", i);

	   return 0;

}
