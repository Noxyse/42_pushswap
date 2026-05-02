/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:39:23 by celgremy          #+#    #+#             */
/*   Updated: 2026/02/10 13:38:10 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char )*s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "ABC";
	char	*s2 = "ABD";

	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
*/
