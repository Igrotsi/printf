/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:45 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/30 22:15:29 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(ssize_t nbr, const char *base)
{
	int	count;
	int	base_len;

	base_len = ft_strlen(base);
	count = 0;
	if (!base || base_len <= 1)
		return (ft_putstr("(nil)"));
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < base_len)
		count += ft_putchar(base[nbr]);
	else
	{
		count += ft_putnbr_base(nbr / base_len, base);
		count += ft_putnbr_base(nbr % base_len, base);
	}
	return (count);
}
