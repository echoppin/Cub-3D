/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:17:07 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 15:56:34 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;

	dest = malloc(sizeof(char) * (n + 1));
	if (!(dest))
		return (NULL);
	ft_strlcpy(dest, s1, n + 1);
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned long	i;

	i = 0;
	ptr = (unsigned char *)s;
	if (n <= 0)
		return ;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
