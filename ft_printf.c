/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:43:22 by lrosby            #+#    #+#             */
/*   Updated: 2021/11/24 20:43:24 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int) write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ((int) write(1, "(null)", 6));
	while (s[i])
		i++;
	return ((int) write(1, s, i));
}

static int	param(char str, va_list ap)
{
	if (str == 'c')
		return (ft_putchar(va_arg(ap, unsigned int)));
	else if (str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (str == 'p')
		return (ft_putnbr_p(va_arg(ap, unsigned long long)));
	else if (str == 'd' || str == 'i')
		return (ft_putnbr_di(va_arg(ap, int)));
	else if (str == 'u')
		return (ft_putnbr_u(va_arg(ap, unsigned int)));
	else if (str == 'x')
		return (ft_putnbr_x(va_arg(ap, unsigned int), 1));
	else if (str == 'X')
		return (ft_putnbr_x(va_arg(ap, unsigned int), 0));
	else if (str == '%')
		return ((int) write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	int		cnt;
	va_list	ap;

	i = 0;
	cnt = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			cnt += param(format[++i], ap);
		else
			cnt += (int) write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (cnt);
}
