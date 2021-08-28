/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:57:59 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 15:58:33 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	rot_right(t_ray *ray)
{
	double	dirx;
	double	plax;

	dirx = ray->dir.x;
	ray->dir.x = ray->dir.x * cos(-ROT_S) - ray->dir.y * sin(-ROT_S);
	ray->dir.y = dirx * sin(-ROT_S) + ray->dir.y * cos(-ROT_S);
	plax = ray->pla.x;
	ray->pla.x = ray->pla.x * cos(-ROT_S) - ray->pla.y * sin(-ROT_S);
	ray->pla.y = plax * sin(-ROT_S) + ray->pla.y * cos(-ROT_S);
}

void	rot_left(t_ray *ray)
{
	double	dirx;
	double	plax;

	dirx = ray->dir.x;
	ray->dir.x = ray->dir.x * cos(ROT_S) - ray->dir.y * sin(ROT_S);
	ray->dir.y = dirx * sin(ROT_S) + ray->dir.y * cos(ROT_S);
	plax = ray->pla.x;
	ray->pla.x = ray->pla.x * cos(ROT_S) - ray->pla.y * sin(ROT_S);
	ray->pla.y = plax * sin(ROT_S) + ray->pla.y * cos(ROT_S);
}

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		quit(mlx);
	else if (keycode == MOVE_UP)
		mlx->move_up = 1;
	else if (keycode == mlx->left_dir)
		mlx->move_left = 1;
	else if (keycode == mlx->right_dir)
		mlx->move_right = 1;
	else if (keycode == MOVE_DOWN)
		mlx->move_down = 1;
	else if (keycode == mlx->right)
		mlx->rot_right = 1;
	else if (keycode == mlx->left)
		mlx->rot_left = 1;
	return (1);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == MOVE_UP)
		mlx->move_up = 0;
	else if (keycode == mlx->left_dir)
		mlx->move_left = 0;
	else if (keycode == mlx->right_dir)
		mlx->move_right = 0;
	else if (keycode == MOVE_DOWN)
		mlx->move_down = 0;
	else if (keycode == mlx->right)
		mlx->rot_right = 0;
	else if (keycode == mlx->left)
		mlx->rot_left = 0;
	return (1);
}

int	key_hook(t_mlx *mlx)
{
	t_mlx	tmp;

	mlx_destroy_image(mlx->mlx, mlx->img);
	tmp.img = mlx_new_image(mlx->mlx, mlx->pos.x, mlx->pos.y);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.len, &tmp.endian);
	if (mlx->move_up == 1)
		mov_up(mlx->cub, mlx->ray);
	else if (mlx->move_left == 1)
		mov_left(mlx->cub, mlx->ray);
	else if (mlx->move_right == 1)
		mov_right(mlx->cub, mlx->ray);
	else if (mlx->move_down == 1)
		mov_down(mlx->cub, mlx->ray);
	else if (mlx->rot_right == 1)
		rot_right(mlx->ray);
	else if (mlx->rot_left == 1)
		rot_left(mlx->ray);
	draw(mlx->cub, &tmp, mlx->ray);
	mlx->img = tmp.img;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (1);
}
