/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:45 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/30 22:15:52 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort_params(const char c, va_list args)
{
	int	count;

	count = 0;
	if (!c)
		return (-1);
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (c == 'X')
		count += ft_putnbr_lb(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'x')
		count += ft_putnbr_lb(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'p')
		count += print_adress(va_arg(args, size_t), "0123456789abcdef");
	return (count);
}
