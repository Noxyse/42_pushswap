/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:48:04 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/15 13:47:42 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_printf(const char *format, ...);
int	ft_strcmp(char *s1, char *s2);

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

t_stack	*ft_init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	ft_fill_stack(int *tab_a, int nb_param, t_stack *a)
{
	int		i;
	t_data	*val_ptr;
	t_node	*new_node;

	i = 0;
	while (i < nb_param)
	{
		val_ptr = malloc(sizeof(t_data));
		if (!val_ptr)
		{
			ft_stackclear(a->head, free);
			return ;
		}
		val_ptr->value = tab_a[i];
		val_ptr->index = 0;
		new_node = ft_stacknew(val_ptr);
		ft_stackadd_back(&(a->head), new_node);
		a->size++;
		i++;
	}
}

void	ft_check_flags(char *flag1, char *flag2)
{
	int	setting;
	// A modifier !
	setting = 0;
	if (ft_strcmp(flag1, "--bench") == 0)
	{
		if (ft_strcmp(flags, "--adaptive") == 0)
			setting = 1;
		else if (ft_strcmp(flags, "--simple") == 0)
			setting = 2;
		else if (ft_strcmp(flags, "--medium") == 0)
			setting = 3;
		else if (ft_strcmp(flags, "--complex") == 0)
			setting = 4;
	}
	else
	{
		if (ft_strcmp(flags, "--adaptive") == 0)
			setting = 0;
		else if (ft_strcmp(flags, "--simple") == 0)
			setting = -1;
		else if (ft_strcmp(flags, "--medium") == 0)
			setting = -2;
		else if (ft_strcmp(flags, "--complex") == 0)
			setting = -3;
	}
}

void	*ft_push_swap(int **stack_a, int nb_param, char *flag1, char *flag2)
{
	t_stack	*a;
	t_stack	*b;
	int		*tab_a;

	tab_a = *stack_a;
	a = ft_init_stack();
	b = ft_init_stack();
	ft_fill_stack(tab_a, nb_param, a);
	ft_value_to_index(a);
	ft_check_flags(flag1, stack_a, nb_param, a, b);
	return (NULL);
}
