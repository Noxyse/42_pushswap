/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:23:21 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/15 16:26:52 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa(t_stack *stack_a, t_bench *bench)
{
	void	*tmp;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	tmp = stack_a->head->content;
	stack_a->head->content = stack_a->head->next->content;
	stack_a->head->next->content = tmp;
	if (bench)
		bench_count_op(bench, "sa");
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b, t_bench *bench)
{
	void	*tmp;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	tmp = stack_b->head->content;
	stack_b->head->content = stack_b->head->next->content;
	stack_b->head->next->content = tmp;
	if (bench)
		bench_count_op(bench, "sb");
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_bench *bench)
{
	void	*tmp;

	if (stack_a && stack_a->head)
	{
		tmp = stack_a->head->content;
		stack_a->head->content = stack_a->head->next->content;
		stack_a->head->next->content = tmp;
	}
	if (stack_b && stack_b->head)
	{
		tmp = stack_b->head->content;
		stack_b->head->content = stack_b->head->next->content;
		stack_b->head->next->content = tmp;
	}
	if (bench)
		bench_count_op(bench, "ss");
	ft_printf("ss\n");
}
