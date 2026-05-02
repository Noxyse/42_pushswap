/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:58:22 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/02 14:27:20 by celgremy         ###   ########.fr       */
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
		if (res > (2147483647L + (sign == -1)) / 10)
		{
			*error = 1;
			return (0);
		}
		res = res * 10 + (ptr[i++] - '0');
	}
	if (ptr[i] != '\0')
		*error = 1;
	return (res * sign);
}

int	*ft_parse_to_int(char **s_str, int nb_param, int *error)
{
	int		*s_int;
	int		i;

	if (!s_str || nb_param <= 0)
		return (NULL);
	s_int = malloc(sizeof(int) * nb_param);
	if (!s_int)
		return (NULL);
	i = 0;
	while (i < nb_param)
	{
		s_int[i] = ft_atoi(s_str[i], error);
		if (*error)
			break ;
		i++;
	}
	return (s_int);
}
