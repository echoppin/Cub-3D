/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:50:18 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/26 17:51:58 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_s;
	size_t	j;

	dst_s = 0;
	j = 0;
	while (dst[dst_s] && dst_s < size)
		dst_s++;
	while (src[j] && (dst_s + j + 1) < size)
	{
		dst[dst_s + j] = src[j];
		j++;
	}
	if (dst_s < size)
		dst[dst_s + j] = '\0';
	return (dst_s + ft_strlen(src));
}
