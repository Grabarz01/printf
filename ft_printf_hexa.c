/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:07:22 by fgrabows          #+#    #+#             */
/*   Updated: 2024/04/10 15:01:23 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%x || %X
static int	ft_countnumbers_hex(unsigned int n)
{
	unsigned int	number;
	int				counter;

	number = n;
	counter = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 16;
		counter++;
	}
	return (counter);
}

static void	ft_print_hexadecimal(unsigned int num, char x,
							char *str_s, char *str_b)
{
	if (num >= 16)
	{
		ft_print_hexadecimal(num / 16, x, str_s, str_b);
		ft_print_hexadecimal(num % 16, x, str_s, str_b);
	}
	else
	{
		if (x == 'x')
			ft_putchar_fd(str_s[num], 1);
		if (x == 'X')
			ft_putchar_fd(str_b[num], 1);
	}
}

int	ft_hexa(int n, char x)
{
	char	*str_s;
	char	*str_b;

	str_s = ft_strdup("0123456789abcdef");
	str_b = ft_strdup("0123456789ABCDEF");
	ft_print_hexadecimal(n, x, str_s, str_b);
	free(str_s);
	free(str_b);
	return (ft_countnumbers_hex(n));
}
