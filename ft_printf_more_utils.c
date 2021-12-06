/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_more_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:23:55 by lrosby            #+#    #+#             */
/*   Updated: 2021/11/28 19:23:56 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_recursive_p(unsigned long long nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (0);
	size += ft_print_recursive_p(nb / 16);
	if (nb % 16 < 10)
		size += ft_putchar('0' + nb % 16);
	else
		size += ft_putchar('a' + nb % 16 - 10);
	return (size);
}

int	ft_putnbr_p(unsigned long long nb)
{
	int	size;

	size = 0;
	size += (int) write(1, "0x", 2);
	if (nb == 0)
		size += ft_putchar('0');
	size += ft_print_recursive_p(nb);
	return (size);
}

static int	ft_print_recursive_x(unsigned int nb, int i)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (0);
	size += ft_print_recursive_x(nb / 16, i);
	if (nb % 16 < 10)
		size += ft_putchar('0' + nb % 16);
	else if (i)
		size += ft_putchar('a' + nb % 16 - 10);
	else
		size += ft_putchar('A' + nb % 16 - 10);
	return (size);
}

int	ft_putnbr_x(unsigned int nb, int i)
{
	int	size;

	size = 0;
	if (nb == 0)
		size += ft_putchar('0');
	size += ft_print_recursive_x(nb, i);
	return (size);
}
