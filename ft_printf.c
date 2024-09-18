/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:25:20 by fgrabows          #+#    #+#             */
/*   Updated: 2024/05/21 17:54:11 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//decider
static int	ft_decider(const char *str, va_list args)
{
	int	x;

	x = 0;
	if (*str == 'c')
		x = ft_print_char(va_arg(args, int));
	else if (*str == 's')
		x = ft_print_string(va_arg(args, const char *));
	else if (*str == 'i' || *str == 'd')
		x = ft_print_digit(va_arg(args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		x = ft_hexa(va_arg(args, unsigned int), *str);
	else if (*str == 'p')
		x = ft_decider_ptr((unsigned long int)va_arg(args, void *));
	else if (*str == 'u')
		x = ft_print_uns(va_arg(args, unsigned int));
	else if (*str == '%')
	{
		write(1, &*str, 1);
		return (1);
	}
	return (x);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start (args, str);
	while (*str)
	{
		if (*str == '%')
		{
			counter += ft_decider(++str, args);
			str++;
		}
		else
		{
			write(1, &*str, 1);
			counter++;
			str++;
		}
	}
	va_end(args);
	return (counter);
}
/*int main()
{
	//%c
	printf("\n%d\n",ft_printf("%ckek",'\0'));
	printf("\n%d\n",printf("%ckek",'\0'));
	printf("\n%d\n",ft_printf("%ckek",'0'));
	printf("\n%d\n",printf("%ckek",'0'));
	//%s
	printf("\n%d\n",ft_printf("%skek","str"));
	printf("\n%d\n",printf("%skek","str"));
	//printf("\n%d\n",printf(" NULL %s NULL ", NULL));
	//printf("\n%d\n",ft_printf(" NULL %s NULL ", NULL));
	//%i || %d
	printf("\n%d\n",ft_printf("%i", -456));
	printf("\n%d\n",printf("%i", -456));
	//%x || %X
	printf("\n%d\n",ft_printf("%x", 16));
	printf("\n%d\n",printf("%x", 16));
	printf("\n%d\n",ft_printf("%x", 0));
	printf("\n%d\n",printf("%x", 0));
	printf("\n%d\n",ft_printf("%x", -200));
	printf("\n%d\n",printf("%x", -200));
	printf("%d",printf("%p", NULL)); //(nil) , 5

}*/

// int main()
// {
// 	unsigned long int a = ULONG_MAX; 
// 	printf("\n%d\n",ft_printf("%p", a));
// 	printf("\n%d\n",printf("%p", a));
// 	printf("\n%d\n",printf("%p", NULL));
// 	printf("\n%d\n",ft_printf("%p", NULL));
// 	printf(" %p\n %p\n", LONG_MIN, LONG_MAX);
// 	printf(" %p\n %p\n ", INT_MIN, INT_MAX);
// 	printf(" %p\n %p\n ", ULONG_MAX, -ULONG_MAX);
// 	printf(" %p\n %p\n ", 0, 0);
// 	printf("%x", -1);
// }

/*int main()
{
	printf("\n%d\n",ft_printf(" %x ", -42));
	printf("\n%d\n",printf(" %x ", -42));
	printf("%d\t",ft_printf("%sss", NULL));
	printf("%d\t",printf("%sss", NULL));
}*/
