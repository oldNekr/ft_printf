/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:20:22 by lrosby            #+#    #+#             */
/*   Updated: 2021/11/24 21:20:24 by lrosby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putnbr_di(int nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_putnbr_x(unsigned int nb, int i);
int	ft_putnbr_p(unsigned long long nb);
int	ft_putstr(char *s);
int	ft_printf(const char *format, ...);
#endif
