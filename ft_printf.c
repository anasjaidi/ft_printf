/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 03:45:24 by ajaidi            #+#    #+#             */
/*   Updated: 2021/11/22 03:45:26 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"
void	print_char(char c)
{
	write(1,&c,1);
}

void	print_number(int nb)
{
	long long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-",1);
		n *= -1;
	}
	if (n >= 10)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	if (n < 10)
		print_char(n + 48);

}

void	print_adr(long long nb)
{
	if (nb >= 16)
	{
		print_adr(nb / 16);
		print_adr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			print_char(nb + 48);
		else
			print_char(nb + 87);
	}
}

void	print_unb(unsigned int nb)
{
	if (nb >= 10)
	{
		print_unb(nb / 10);
		print_unb(nb % 10);
	}
	if (nb < 10)
		print_char(nb + 48);
	
}
 
void	print_hex(unsigned int nb, int s)
{
	if (nb >= 16)
	{
		print_hex(nb / 16, s);
		print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			print_char(nb + 48);
		else
		{

			if (s == 1)
				print_char(nb + 87);
			else
				print_char(nb + 55);
		}
	}
}

void	print_str(char	*str)
{
	if (!str)
		return;
	while(*str)
		write(1,str++,1);
}

int	ft_printf(char *format, ...)
{
	int	i = 0;
	va_list	ptr;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			write(1,&format[i],1);
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				print_char(va_arg(ptr, int));
			if (format[i + 1] == '%')
				write(1,"%",1);
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
				print_number(va_arg(ptr, int));
			if (format[i + 1] == 'u')
				print_unb(va_arg(ptr,unsigned int));
			if (format[i + 1] == 'x')
				print_hex(va_arg(ptr,unsigned int) , 1);
			if (format[i + 1] == 'X')
				print_hex(va_arg(ptr,unsigned int) , 2);
			if (format[i + 1] == 'p')
			{
				write(1,"0x",2);
				print_adr(va_arg(ptr,long long));
			}
			if (format[i + 1] == 's')
				print_str(va_arg(ptr, char*));
			i++;
		}
		i++;
	}
	va_end(ptr);
	return (0);
}
/*
#include <stdio.h>

int main()
{
	int a;
	int	*p = NULL;
	printf("anas jaid is %c %% allah akbar %d & %i & %s & %u  & %u & %p & %x $ %X\n", 'd', INT_MIN, INT_MAX, "anas jaidi", INT_MIN, -13, p , INT_MAX, INT_MAX);
	ft_printf("anas jaid is %c %% allah akbar %d & %i & %s & %u  & %u & %p $ %x $ %X", 'd', INT_MIN, INT_MAX, "anas jaidi", INT_MIN, -13, p, INT_MAX, INT_MAX);
	return 0;
}*/
