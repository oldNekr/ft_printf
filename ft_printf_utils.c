/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:08:34 by lrosby            #+#    #+#             */
/*   Updated: 2021/11/28 19:08:36 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_recursive(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (0);
	size += ft_print_recursive(nb / 10);
	if (nb > 0)
		size += ft_putchar('0' + nb % 10);
	else
		size += ft_putchar('0' - nb % 10);
	return (size);
}

int	ft_putnbr_di(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		size += ft_putchar('0');
	if (nb < 0)
		size += ft_putchar('-');
	size += ft_print_recursive(nb);
	return (size);
}

static int	ft_print_recursive_u(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (0);
	size += ft_print_recursive_u(nb / 10);
	size += ft_putchar('0' + nb % 10);
	return (size);
}

int	ft_putnbr_u(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		size += ft_putchar('0');
	size += ft_print_recursive_u(nb);
	return (size);
}
