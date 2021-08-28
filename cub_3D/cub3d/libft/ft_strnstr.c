/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:00:22 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 18:28:46 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (i < n && big[i])
	{
		if (big[i] == *little)
		{
			j = 0;
			while (i + j < n && little[j] == big[i + j])
			{
				j++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}
