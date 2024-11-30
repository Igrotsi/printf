/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flahalle <flahalle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:41:45 by flahalle          #+#    #+#             */
/*   Updated: 2024/11/30 22:13:22 by flahalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_putchar(char c)
// {
// 	return (write(1, &c, 1));
// }

// static int	ft_putstr(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (ft_putstr("(null)"));
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// static int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// static int	ft_putnbr_lb(unsigned long nb, const char *base)
// {
// 	int	count;
// 	int	base_len;

// 	count = 0;
// 	base_len = ft_strlen(base);
// 	if (nb < (unsigned long)base_len)
// 		count += ft_putchar(base[nb]);
// 	else
// 	{
// 		count += ft_putnbr_lb(nb / base_len, base);
// 		count += ft_putnbr_lb(nb % base_len, base);
// 	}
// 	return (count);
// }

// static int	ft_putnbr_base(ssize_t nbr, const char *base)
// {
// 	int	count;
// 	int	base_len;

// 	base_len = ft_strlen(base);
// 	count = 0;
// 	if (!base || base_len <= 1)
// 		return (ft_putstr("(nil)"));
// 	if (nbr < 0)
// 	{
// 		count += ft_putchar('-');
// 		nbr = -nbr;
// 	}
// 	if (nbr < base_len)
// 		count += ft_putchar(base[nbr]);
// 	else
// 	{
// 		count += ft_putnbr_base(nbr / base_len, base);
// 		count += ft_putnbr_base(nbr % base_len, base);
// 	}
// 	return (count);
// }

// static int	ft_putnbr(int nb)
// {
// 	int	count;

// 	count = 0;
// 	if (nb == -2147483648)
// 	{
// 		count += ft_putstr("-2147483648");
// 		return (count);
// 	}
// 	if (nb < 0)
// 	{
// 		count += ft_putchar('-');
// 		nb = -nb;
// 	}
// 	if (nb >= 0 && nb < 10)
// 	{
// 		count += ft_putchar(nb + '0');
// 	}
// 	else
// 	{
// 		count += ft_putnbr(nb / 10);
// 		count += ft_putnbr(nb % 10);
// 	}
// 	return (count);
// }

// static int	print_adress(size_t ptr, char *base)
// {
// 	int	count;

// 	count = 0;
// 	if ((char *)ptr == NULL)
// 		return (count += ft_putstr("(nil)"));
// 	count += ft_putstr("0x");
// 	count += ft_putnbr_lb(ptr, base);
// 	return (count);
// }

// static int	sort_params(const char c, va_list args)
// {
// 	int	count;

// 	count = 0;
// 	if (!c)
// 		return (-1);
// 	if (c == 'c')
// 		count += ft_putchar(va_arg(args, int));
// 	else if (c == 's')
// 		count += ft_putstr(va_arg(args, char *));
// 	else if (c == 'd' || c == 'i')
// 		count += ft_putnbr(va_arg(args, int));
// 	else if (c == 'u')
// 		count += ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
// 	else if (c == 'X')
// 		count += ft_putnbr_lb(va_arg(args, unsigned int), "0123456789ABCDEF");
// 	else if (c == 'x')
// 		count += ft_putnbr_lb(va_arg(args, unsigned int), "0123456789abcdef");
// 	else if (c == '%')
// 		count += ft_putchar('%');
// 	else if (c == 'p')
// 		count += print_adress(va_arg(args, size_t), "0123456789abcdef");
// 	return (count);
// }

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += sort_params(format[i], args);
			if (count == -1)
				break ;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	void	*data = "salut";
// 	//ft_printf(" %p %p ", 0,0);
// 	printf("%i", ft_printf("%x", 0));
// 	//printf("%s\n\n", "________");
// 	//printf("%s", NULL);
// 	return (0);
// }
