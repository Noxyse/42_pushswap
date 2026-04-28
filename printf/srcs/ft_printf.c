/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-23 13:56:18 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-23 13:56:18 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_check_txt(format[i + 1], &args);
			count += ft_check_hex(format[i + 1], &args);
			count += ft_check_baset(format[i + 1], &args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
