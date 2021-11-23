
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int x;
	int y;
	int a;
	int	*p = &a;
	x = printf("anas jaid is %c %% allah akbar %d & %i & %s & %u  & %u & %p & %x $ %X\n", 'd', INT_MIN, INT_MAX, "anas jaidi", INT_MIN, -13, p , INT_MAX, INT_MAX);
	y = ft_printf("anas jaid is %c %% allah akbar %d & %i & %s & %u  & %u & %p $ %x $ %X\n", 'd', INT_MIN, INT_MAX, "anas jaidi", INT_MIN, -13, p, INT_MAX, INT_MAX);
	printf("%d	%d", x, y);
	return 0;
}
