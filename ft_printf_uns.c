/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:04:11 by fgrabows          #+#    #+#             */
/*   Updated: 2024/04/10 15:04:39 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%u
static int	ft_countnumbers_uns(unsigned long n)
{
	unsigned long	number;
	int				counter;

	number = n;
	counter = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

int	ft_print_uns(unsigned int n)
{
	unsigned long	num;

	num = n;
	if (num >= 10)
	{
		ft_print_uns(num / 10);
		ft_print_uns(num % 10);
	}
	else
		ft_putchar_fd(num + '0', 1);
	return (ft_countnumbers_uns(n));
}
