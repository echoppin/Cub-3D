/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:40:13 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 18:46:18 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen_base(int n, int base)
{
	int	j;

	j = 0;
	if (n <= 0)
	{
		n *= -1;
		j++;
	}
	while (n > 0)
	{
		n /= base;
		j++;
	}
	return (j);
}