/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:03:17 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 18:29:35 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	size;
	char	*dest;

	start = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen((char *)s1);
	while (ft_set(set, s1[start]))
		start++;
	if (start != size)
	{
		while (ft_set(set, s1[size - 1]))
			size--;
	}
	dest = ft_substr(s1, start, size - start);
	return (dest);
}
