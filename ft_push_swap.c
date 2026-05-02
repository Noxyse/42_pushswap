/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:48:04 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/02 10:20:36 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_lstsize(t_stack *lst);

int	ft_compute_disorder(int *a, int nb_arg)
{
	unsigned long	mistakes;
	unsigned long	total_pairs;
	int				i;
	int				j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < nb_arg - 1)
	{
		j = i + 1;
		while (j < nb_arg - 1)
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	if (mistakes * 5 < total_pairs || total_pairs == 0)
		return (1);
	else if ((mistakes * 2 >= total_pairs))
		return (3);
	return (2);
}

void	*ft_push_swap(int **stack_a)
{
	int	**stack_b;
	int	select_algo;
	int	size;

	size = ft_lstsize(a);
	select_algo = ft_compute_disorder(a, size);
	if (select_algo == 1)
		ft_simple_algo(stack_a, stack_b, size);
	else if (select_algo == 2)
		ft_medium_algo(stack_a, stack_b, size);
	else
		ft_complex_algo(stack_a, stack_b, size);
}
