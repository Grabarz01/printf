/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:09:33 by fgrabows          #+#    #+#             */
/*   Updated: 2024/04/10 14:48:11 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//%i || %d
static void	ft_int2ascii(char *str, int n, int x)
{
	int	i;

	i = x;
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n != 0)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	str[x] = '\0';
}

static int	ft_countnumbers(int n)
{
	int	number;
	int	counter;

	number = n;
	counter = 0;
	if (number < 0)
	{
		counter++;
		number = number * (-1);
	}
	while (number != 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

static const char	*ft_print_itoa(int n)
{
	char	*str;
	int		x;

	x = ft_countnumbers(n);
	if (n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	ft_int2ascii(str, n, x);
	return (str);
}

int	ft_print_digit(int n)
{
	const char	*str;
	int			x;

	str = ft_print_itoa(n);
	ft_putstr_fd((char *)str, 1);
	x = ft_strlen(str);
	free((void *) str);
	return (x);
}
