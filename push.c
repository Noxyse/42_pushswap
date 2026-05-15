/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:09:05 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/15 16:21:42 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !stack_b->head)
		return ;
	tmp = ft_remove_head(&stack_b->head);
	ft_stackadd_front(&stack_a->head, tmp);
	stack_a->size++;
	stack_b->size--;
	if (bench)
		bench_count_op(bench, "pa");
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	t_node	*tmp;

	if (!stack_a || !stack_b || !stack_a->head)
		return ;
	tmp = ft_remove_head(&stack_a->head);
	ft_stackadd_front(&stack_b->head, tmp);
	stack_a->size--;
	stack_b->size++;
	if (bench)
		bench_count_op(bench, "pb");
	ft_printf("pb\n");
}
