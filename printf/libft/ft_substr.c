/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celgremy <celgremy@student.42belgium.be>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-13 13:57:39 by celgremy          #+#    #+#             */
/*   Updated: 2026-04-13 13:57:39 by celgremy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	i = start;
	j = 0;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (j < len && s[i] != '\0')
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	*res;

	res = ft_substr("Hello World", 6, 5);
	printf("Test 1: %s\n", res); // World
	free(res);
	res = ft_substr("Hello", 2, 10);
	printf("Test 2: %s\n", res); // lo
	free(res);
	res = ft_substr("Hello", 10, 3);
	printf("Test 3: '%s'\n", res); // ""
	free(res);
	return (0);
}*/
