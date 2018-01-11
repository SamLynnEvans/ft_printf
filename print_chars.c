#include "ft_printf.h"

t_print_chars g_pf_char_tab[] = {
	{"c", &pf_putchar},
	{"s", &pf_putstr},
	{"%", &pf_putchar},
};

void	pf_putchar(char *str, char *flags)
{
	char c;

	ft_putstr("entered");
	c = str[0];
	if (*flags)
		;
	ft_putchar(c);
}

void	pf_putstr(char *str, char *flags)
{
	if (*flags)
		;
	ft_putstr(str);
}

void	print_chars(char *prnt_str, char *flags, char *c, int star)
{
	int		j;

	star = 0;
	j = 0;
	while (j < 3)
	{
		if (*c == *g_pf_char_tab[j].c)
		{
			g_pf_char_tab[j].print(prnt_str, flags);
			break ;
		}
		j++;
	}
}
