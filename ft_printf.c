/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:45 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/29 19:05:59 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	len = 0;
	if (nbr >= 0 && nbr < ft_strlen(base))
		ft_putchar(base[nbr]);
	else
	{
		len += ft_putnbr_base(nbr / ft_strlen(base), base);
		len += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	return(len);
}

static int	printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
	}
	return (i);
}

static int	sort_params(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += write(1, va_arg(args, char), 1);
	if (c == 's')
		len += printstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		len += ft_putnbr_base(va_arg(args, int), "0123456789");
	if (c == 'u')
		len += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	if (c == 'X')
		len += ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	if (c == 'x')
		len += ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	if (c == '%')
		len += write(1, va_arg(args, char), 1);
	if (c == 'p')
	{
		printstr("0x");
		len += ft_putnbr_base(va_arg(args, long int), "0123456789abcdef");
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += sort_params(format[i], args);
			i++;
		}
		else
			len += write(1, format, 1);
		i++;
	}
	return (i);
}
