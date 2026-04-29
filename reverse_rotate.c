/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:54:32 by mgedeon           #+#    #+#             */
/*   Updated: 2026/04/29 15:15:23 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*tmp;

	if (!stack_a || !stack_a->head)
		return ;
	tmp = remove_tail(&stack_a->head);
	stackadd_front(&stack_a->head, tmp);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->head)
		return ;
	tmp = remove_tail(&stack_b->head);
	stackadd_front(&stack_b->head, tmp);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
