/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:28:09 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:42:30 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_conversion(char c, va_list ap, int *i)
{
	char			chr;
	int				d;
	char			*s;

	if (c == 'c')
	{
		chr = va_arg(ap, int);
		ft_putchar(chr, i);
	}
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(ap, int);
		ft_putnbr(d, i);
	}
	else if (c == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s, i);
	}
	else if (c == '%')
		ft_putchar('%', i);
	else
		ft_conversion2(c, ap, i);
}

void	ft_conversion2(char c, va_list ap, int *i)
{
	unsigned int	u;
	unsigned long	p;

	if (c == 'u')
	{
		u = va_arg(ap, unsigned int);
		ft_unsigned(u, i);
	}
	else if (c == 'x')
	{
		u = va_arg(ap, unsigned int);
		ft_hex(u, i);
	}
	else if (c == 'X')
	{
		u = va_arg(ap, unsigned int);
		ft_hexu(u, i);
	}
	else if (c == 'p')
	{
		p = va_arg(ap, unsigned long);
		ft_putchar('0', i);
		ft_putchar('x', i);
		ft_pointer(p, i);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_conversion(*fmt, ap, &i);
			fmt++;
		}
		if (*fmt != '%' && *fmt != '\0')
		{
			ft_putchar(*fmt++, &i);
		}
	}
	va_end(ap);
	return (i);
}
