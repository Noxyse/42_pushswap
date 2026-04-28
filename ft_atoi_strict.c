/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 19:58:22 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/26 20:37:15 by celgremy         ###   #######belgium.be */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_strict(char *ptr, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	i = 0;
	sign = 1;
	if (ptr[i] == '-')
	{
		if (ptr[i + 1] >= '0' && ptr[i + 1] <= '9')
		{
			sign = -1;
			i++;
		}
		else
			*error = 1;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
		res = res * 10 + (ptr[i++] - '0');
	if (!(ptr[i] >= '0' && ptr[i] <= '9') && ptr[i] != '\0')
		*error = 1;
	if (res * sign > 2147483647 || res * sign < -2147483648)
		*error = 1;
	return (res * sign);
}
