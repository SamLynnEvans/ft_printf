#include <locale.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_CTYPE, "");
	int	 a = '\xE7';
	char *p = "ksafasjfn";

	printf("char = %ls\n", L"Schöne Grüße");
	printf("char = %20s\n", NULL);

	printf("char = %lc\n", a);
	printf("char = %20.5ls", L"Schöne Grüße");
	printf("\033[10;34m char = %20.5ls\n", L"Schöne Grüße");
	printf("\033[10;34m char = {}%20.5ls\n", L"Schöne Grüße");
	printf("\033[10;34m char = %20.5llp\n", p);
	printf("%20.3p|\n", NULL); 
}
