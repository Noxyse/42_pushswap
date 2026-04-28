/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:04:53 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/28 13:12:43 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*tmp;

	if (!stack_a)
		return ;
	tmp = stack_a->head;
	ft_lstdelone(stack_a->first);
	ft_lstadd_back(*stack_a, tmp);
}
