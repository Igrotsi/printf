/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_lb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:45 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/30 22:15:31 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_lb(unsigned long nb, const char *base)
{
	int	count;
	int	base_len;

	count = 0;
	base_len = ft_strlen(base);
	if (nb < (unsigned long)base_len)
		count += ft_putchar(base[nb]);
	else
	{
		count += ft_putnbr_lb(nb / base_len, base);
		count += ft_putnbr_lb(nb % base_len, base);
	}
	return (count);
}
