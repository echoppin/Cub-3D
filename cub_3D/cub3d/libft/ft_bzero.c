/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:24:33 by echoppin          #+#    #+#             */
/*   Updated: 2020/11/24 11:34:14 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
