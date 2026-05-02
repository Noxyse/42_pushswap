/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:58:22 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/02 13:20:25 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi(char *ptr, int *error)
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

int	*ft_parse_to_int(char **s_str, int size, int *error)
{
	int		*s_int;
	int		i;

	if (!s_str || size <= 0)
		return (NULL);
	s_int = malloc(sizeof(int) * size);
	if (!s_int)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s_int[i] = ft_atoi(s_str[i], error);
		i++;
	}
	return (s_int);
}
