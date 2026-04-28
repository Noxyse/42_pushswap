/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-24 10:28:08 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-24 10:28:08 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stddef.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

int	ft_check_txt(char c, va_list *param)
{
	char	*str;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(*param, int), 1);
		return (1);
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 's')
	{
		str = va_arg(*param, char *);
		if (str == NULL)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (0);
}
