/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:05:10 by fgrabows          #+#    #+#             */
/*   Updated: 2024/04/10 15:07:51 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countnumbers_ptr(unsigned long long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		counter++;
	}
	return (counter);
}

static int	ft_print_ptr(unsigned long long int n, char *str)
{
	unsigned long long int	num;

	num = n;
	if (num >= 16)
	{
		ft_print_ptr(num / 16, str);
		ft_print_ptr(num % 16, str);
	}
	else
		ft_putchar_fd(str[num], 1);
	return (ft_countnumbers_ptr(n) + 2);
}

int	ft_decider_ptr(unsigned long int n)
{
	char			*str;
	unsigned int	x;

	str = ft_strdup("0123456789abcdef");
	if (n == 0)
	{
		write(1, "(nil)", 5);
		free(str);
		return (5);
	}
	else
	{
		write(1, "0x", 2);
		x = ft_print_ptr(n, str);
		free(str);
		return (x);
	}
}
