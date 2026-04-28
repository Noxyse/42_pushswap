/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-24 14:37:15 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-24 14:37:15 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lhex_putnbr_fd(unsigned long n, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
		ft_lhex_putnbr_fd(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

void	ft_uhex_putnbr_fd(unsigned long n, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n >= 16)
		ft_uhex_putnbr_fd(n / 16, fd);
	ft_putchar_fd(base[n % 16], fd);
}

int	ft_hexlen(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_check_hex(char c, va_list *param)
{
	void			*ptr;
	unsigned int	n;

	if (c == 'p')
	{
		ptr = va_arg(*param, void *);
		if (ptr == NULL)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		ft_lhex_putnbr_fd((unsigned long)ptr, 1);
		return (ft_hexlen((unsigned long)ptr) + 2);
	}
	else if (c == 'x' || c == 'X')
	{
		n = va_arg(*param, unsigned int);
		if (c == 'x')
			ft_lhex_putnbr_fd(n, 1);
		else
			ft_uhex_putnbr_fd(n, 1);
		return (ft_hexlen(n));
	}
	return (0);
}
