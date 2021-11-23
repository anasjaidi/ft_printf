/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajaidi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:36:31 by ajaidi            #+#    #+#             */
/*   Updated: 2021/11/23 18:37:08 by ajaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_number(n / 10);
		len += print_number(n % 10);
	}
	if (n < 10)
		len += print_char(n + 48);
	return (len);
}

int	print_adr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_adr(nb / 16);
		len += print_adr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
			len += print_char(nb + 87);
	}
	return (len);
}

int	print_unb(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_unb(nb / 10);
		len += print_unb(nb % 10);
	}
	if (nb < 10)
		len += print_char(nb + 48);
	return (len);
}

int	print_hex(unsigned int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, s);
		len += print_hex(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + 48);
		else
		{
			if (s == 1)
				len += print_char(nb + 87);
			else
				len += print_char(nb + 55);
		}
	}
	return (len);
}

int	print_str(char	*str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
