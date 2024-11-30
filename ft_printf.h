/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:05:06 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/30 22:13:42 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_strlen(const char *str);
int	ft_putnbr_lb(unsigned long nb, const char *base);
int	ft_putnbr_base(ssize_t nbr, const char *base);
int	ft_putnbr(int nb);
int	print_adress(size_t ptr, char *base);
int	sort_params(const char c, va_list args);

#endif
