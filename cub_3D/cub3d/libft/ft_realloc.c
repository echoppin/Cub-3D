/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:25:47 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 18:21:54 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ex, size_t size)
{
	void	*tmp;

	if (!ptr)
		return ((void *)malloc(size));
	tmp = (void *)malloc(size);
	if (!tmp)
		return (NULL);
	ft_memmove(tmp, ptr, ex);
	free(ptr);
	ptr = ((void *)malloc(size));
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, tmp, size);
	free(tmp);
	return (ptr);
}
