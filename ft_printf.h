/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrabows <fgrabows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:13:55 by fgrabows          #+#    #+#             */
/*   Updated: 2024/04/25 12:09:30 by fgrabows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(char a);
int	ft_print_digit(int n);
int	ft_print_string(const char *str);
int	ft_hexa(int n, char x);
int	ft_decider_ptr(unsigned long int n);
int	ft_print_uns(unsigned int n);

#endif