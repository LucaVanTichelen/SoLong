/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:36:41 by lvan-tic          #+#    #+#             */
/*   Updated: 2022/02/26 12:42:21 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int nb, int *i)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10, i);
		ft_putchar('8', i);
	}
	if (nb < 0 && nb > -2147483648)
	{
		ft_putchar('-', i);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, i);
	}
	if (nb != -2147483648)
	{
		ft_putchar(nb % 10 + '0', i);
	}
}

void	ft_unsigned(unsigned int nb, int *i)
{
	if (nb >= 10)
	{
		ft_unsigned(nb / 10, i);
	}
	ft_putchar(nb % 10 + '0', i);
}

void	ft_hex(unsigned int nb, int *i)
{
	if (nb >= 16)
		ft_hex(nb / 16, i);
	if (nb % 16 >= 10)
		ft_putchar((nb % 16) % 10 + 97, i);
	else
		ft_putchar(nb % 16 + '0', i);
}

void	ft_hexu(unsigned int nb, int *i)
{
	if (nb >= 16)
		ft_hexu(nb / 16, i);
	if (nb % 16 >= 10)
		ft_putchar((nb % 16) % 10 + 65, i);
	else
		ft_putchar(nb % 16 + '0', i);
}

void	ft_pointer(unsigned long p, int *i)
{
	if (p >= 16)
		ft_pointer(p / 16, i);
	if (p % 16 >= 10)
		ft_putchar((p % 16) % 10 + 97, i);
	else
		ft_putchar(p % 16 + '0', i);
}
