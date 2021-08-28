/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:06:30 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 16:07:21 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	offset(t_cub *cub, t_mlx *mlx, int fd)
{
	int		tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * cub->rx * cub->ry;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &cub->rx, 4);
	write(fd, &cub->ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &mlx->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	save(t_cub *cub, t_mlx *mlx)
{
	int		fd;
	int		x;
	int		y;
	int		c;

	y = cub->ry;
	fd = open("save.bmp", O_CREAT | O_RDWR);
	if (fd == -1)
	{
		system("rm -f save.bmp");
		fd = open("save.bmp", O_CREAT | O_RDWR);
	}
	offset(cub, mlx, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < cub->rx)
		{
			c = mlx_pixel_get(mlx, y, x);
			write(fd, &c, 4);
			x++;
		}
		y--;
	}
	system("chmod 777 save.bmp");
}
