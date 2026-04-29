/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:51:15 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/29 15:22:05 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	int		error;
	int		**splited;

	if (argc < 2)
	{
		ft_printf("Error");
		return (0);
	}
	error = 0;
	i = argc - 1;
	while (i > 2)
	{
		ft_strjoin(argv[i], argv[i - 1]);
		i--;
	}
	splited = ft_check_error(argv[2], &error);
	if (error == 1)
	{
		printf("Error\n");
		return (0);
	}
	ft_push_swap(splited);
	return (0);
}
