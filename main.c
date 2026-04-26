/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:51:15 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/26 14:58:10 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
	{
		ft_printf("Missing stack");
		return (0);
	}
	stack_a = argv;
	ft_printf("Before pushswap : [ %d ]\n", stack_a);
	ft_push_swap(stack_a);
	ft_printf("After pushswap : [ %d ]\n", stack_a);
	return (0);
}
