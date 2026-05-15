/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 11:04:53 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/15 16:22:29 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra(t_stack *stack_a, t_bench *bench)
{
	t_node	*tmp;

	if (!stack_a || !stack_a->head)
		return ;
	tmp = ft_remove_head(&stack_a->head);
	ft_stackadd_back(&stack_a->head, tmp);
	if (bench)
		bench_count_op(bench, "ra");
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b, t_bench *bench)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->head)
		return ;
	tmp = ft_remove_head(&stack_b->head);
	ft_stackadd_back(&stack_b->head, tmp);
	if (bench)
		bench_count_op(bench, "rb");
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	t_node	*tmp;

	if (stack_a && stack_a->head)
	{
		tmp = ft_remove_head(&stack_a->head);
		ft_stackadd_back(&stack_a->head, tmp);
	}
	if (stack_b && stack_b->head)
	{
		tmp = ft_remove_head(&stack_b->head);
		ft_stackadd_back(&stack_b->head, tmp);
	}
	if (bench)
		bench_count_op(bench, "rr");
	ft_printf("rr\n");
}
