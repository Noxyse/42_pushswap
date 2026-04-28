/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:48:04 by celgremy          #+#    #+#             */
/*   Updated: 2026/04/28 16:34:01 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int		ft_lstsize(t_stack *lst);

void	*ft_push_swap(int *a, int *b, int *error)
{
	int	select_algo;
	int	size;

	size = ft_lstsize(a);
	select_algo = ft_compute_disorder(a, size);
	if (select_algo == 1)
		ft_simple_algo(a, b, error, size);
	else if (select_algo == 2)
		ft_medium_algo(a, b, error, size);
	else
		ft_complex_algo(a, b, error, size);
}
