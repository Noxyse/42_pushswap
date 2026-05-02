/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:48:04 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/02 15:45:14 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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
	int		*val_ptr;
	t_node	*new_node;

	i = 0;
	while (i < nb_param)
	{
		val_ptr = malloc(sizeof(int));
		if (!val_ptr)
			return ;
		*val_ptr = tab[i];
		new_node = ft_stacknew(val_ptr);
		ft_stackadd_back(&(a->head), new_node);
		a->tail = new_node;
		a->size++;
		i++;
	}
}

void	*ft_push_swap(int **stack_a, int nb_param, char flags)
{
	t_stack	*a;
	t_stack	*b;
	int		tab_a;

	tab_a = *stack_a;
	a = ft_init_stack();
	b = ft_init_stack();
	ft_fill_stack(tab_a, nb_param, &a);
}
