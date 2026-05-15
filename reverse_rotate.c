/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:54:32 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/15 16:26:19 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_stack *stack_a, t_bench *bench)
{
	t_node	*tmp;

	if (!stack_a || !stack_a->head)
		return ;
	tmp = ft_remove_tail(&stack_a->head);
	ft_stackadd_front(&stack_a->head, tmp);
	if (bench)
		bench_count_op(bench, "rra");
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, t_bench *bench)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->head)
		return ;
	tmp = ft_remove_tail(&stack_b->head);
	ft_stackadd_front(&stack_b->head, tmp);
	if (bench)
		bench_count_op(bench, "rrb");
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	t_node	*tmp;

	if (stack_a && stack_a->head)
	{
		tmp = ft_remove_tail(&stack_a->head);
		ft_stackadd_front(&stack_a->head, tmp);
	}
	if (stack_b && stack_b->head)
	{
		tmp = ft_remove_tail(&stack_b->head);
		ft_stackadd_front(&stack_b->head, tmp);
	}
	if (bench)
		bench_count_op(bench, "rrr");
	ft_printf("rrr\n");
}
