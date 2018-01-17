#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"

typedef int		(*p_balls)(int *);

typedef	struct	s_balls
{
	p_balls ball;
}				t_balls;

int		ballacher(int mod[2]);

//t_balls g_tab = {&ballacher};

int		ballacher(int mod[2])
{
	ft_intdebug(mod[0], "mod[0]");
	ft_intdebug(mod[1], "mod[1]");
	return (0);
}

int main()
{
	int mod[2];
	t_balls ballin;

	ballin.ball = &ballacher;
	
	mod[0] = 1;	
	mod[1] = 2;
	ballin.ball(mod);
}
