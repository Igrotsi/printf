/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:45 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/30 22:15:49 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_adress(size_t ptr, char *base)
{
	int	count;

	count = 0;
	if ((char *)ptr == NULL)
		return (count += ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_lb(ptr, base);
	return (count);
}
