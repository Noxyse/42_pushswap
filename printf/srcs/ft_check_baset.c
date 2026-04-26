/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_baset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-24 14:38:13 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-24 14:38:13 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd);

void	ft_uputnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
		ft_uputnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

int	ft_intlen(int n)
{
	long	nb;
	int		len;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	ft_uintlen(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_check_baset(char c, va_list *param)
{
	int	nb;

	if (c == 'd' || c == 'i')
	{
		nb = va_arg(*param, int);
		ft_putnbr_fd(nb, 1);
		return (ft_intlen(nb));
	}
	else if (c == 'u')
	{
		nb = va_arg(*param, unsigned int);
		ft_uputnbr_fd(nb, 1);
		return (ft_uintlen(nb));
	}
	return (0);
}
