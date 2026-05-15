/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgedeon <mgedeon@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:36:31 by mgedeon           #+#    #+#             */
/*   Updated: 2026/05/15 17:00:00 by mgedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_bench	*bench_init(void)
{
	t_bench	*bench;

	bench = ft_calloc(1, sizeof(t_bench));
	if (!bench)
		return (NULL);
	return (bench);
}

void	which_strat(char *flags)
{
	int	res_flags;

	res_flags = ft_check_flags(flags);
	if (res_flags == 1)
		ft_printf("Strategy: %s | Complexity class: O(n²)", flags);
	else if (res_flags == 2)
		ft_printf("Strategy: %s | Complexity class: O(n√n)", flags);
	else if (res_flags == 3)
		ft_printf("Strategy: %s | Complexity class: O(nlogn)", flags);
}

void	bench_count_op(t_bench *bench, char *op)
{
	if (!bench)
		return ;
	if (ft_strcmp(op, "sa") == 0)
		bench->sa++;
	else if (ft_strcmp(op, "sb") == 0)
		bench->sb++;
	else if (ft_strcmp(op, "ss") == 0)
		bench->ss++;
	else if (ft_strcmp(op, "pa") == 0)
		bench->pa++;
	else if (ft_strcmp(op, "pb") == 0)
		bench->pb++;
	else if (ft_strcmp(op, "rra") == 0)
		bench->rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		bench->rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		bench->rrr++;
	else if (ft_strcmp(op, "ra") == 0)
		bench->ra++;
	else if (ft_strcmp(op, "rb") == 0)
		bench->rb++;
	else if (ft_strcmp(op, "rr") == 0)
		bench->rr++;
}
