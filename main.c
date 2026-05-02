/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 14:51:15 by celgremy          #+#    #+#             */
/*   Updated: 2026/05/02 13:34:21 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	**ft_join_split(int size, char **tab, int *error, int *count)
{
	char	*temp;
	char	*join_str;
	char	**res;
	int		i;

	join_str = ft_strdup("");
	i = 2;
	while (i < size)
	{
		temp = ft_strjoin(join_str, tab[i]);
		free(join_str);
		join_str = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	res = ft_split(join_str, ' ');
	free(join_str);
	while (res && res[*count])
		(*count)++;
	if (*count > 500)
		*error = 1;
	return (res);
}

int	main(int argc, char **argv)
{
	char	**args_split;
	int		size;
	int		error;
	int		*stack_a;

	if (argc < 3)
		return (ft_printf("Error\n"), 0);
	size = 0;
	error = 0;
	args_split = ft_join_split(argc, argv, &error, &size);
	if (!args_split || error)
	{
		ft_free_split(args_split);
		return (ft_printf("Error\n"), 0);
	}
	stack_a = ft_parse_to_int(args_split, size, &error);
	ft_free_split(args_split);
	if (error == 1 || !stack_a || ft_dupli(stack_a, size))
		return (free(stack_a), ft_printf("Error\n"), 0);
	ft_push_swap(&stack_a, size, argv[1]);
	free(stack_a);
	return (0);
}
