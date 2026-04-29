/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:58:22 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/29 13:45:42 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int

int	ft_atoi_strict(char *ptr, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' ')
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
		sign = 44 - ptr[i++];
	if (!(ptr[i] >= '0' && ptr[i] <= '9'))
		*error = 1;
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		res = res * 10 + (ptr[i++] - '0');
		if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
		{
			*error = 1;
			return (0);
		}
	}
	if (ptr[i] != '\0')
		*error = 1;
	return (res * sign);
}

int	ft_check_error(char *ptr)
{
	int	*error;

	error = 0;
	// SUITE DE LA FONCTION
	// CHECK SI *error != 0
}
