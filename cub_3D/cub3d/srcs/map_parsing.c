/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:03:42 by echoppin          #+#    #+#             */
/*   Updated: 2021/07/06 12:13:06 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	get_map(t_cub *cub)
{
	int		i;
	size_t	len;

	i = 1;
	len = sizeof(char *);
	cub->map = (void *)malloc(len * 2);
	if (!cub->map)
		ft_exit(EXIT_FAILURE, cub, "Malloc break in init_cub\n");
	while (get_next_line(cub->fd, &cub->map[0]) > 0 && !cub->map[0][0])
		free(cub->map[0]);
	while (get_next_line(cub->fd, &cub->map[i]) > 0)
	{
		cub->map = ft_realloc(cub->map, len * (i + 1), len * (i + 2));
		i++;
	}
	cub->height = i;
	free(cub->map[i]);
	cub->map[i] = NULL;
}

void	count_sprites(t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == '2')
	{
		cub->spr[cub->spr_nbr].x = i;
		cub->spr[cub->spr_nbr].y = j;
		cub->spr_nbr++;
	}
}

void	check_map(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			count_sprites(cub, i, j);
			if (!ft_strchr(" 012NSEW", cub->map[i][j]))
				ft_exit(EXIT_FAILURE, cub, "Wrong map\n");
			if (ft_strchr("NSEW", cub->map[i][j]))
			{
				if (cub->cp != 'X' && cub->cp)
					ft_exit(EXIT_FAILURE, cub, "Wrong map\n");
				cub->cp = cub->map[i][j];
				cub->start.x = j;
				cub->start.y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_check(t_cub *cub, int x, int y, int overflow)
{
	if (x < 0 || y < 0 || !cub->map[y][x] || cub->map[y][x] == ' ')
		ft_exit(EXIT_FAILURE, cub, "Wrong map\n");
	if (overflow > 30000)
		ft_exit(EXIT_FAILURE, cub, "Map is too big\n");
	if (cub->map[y][x] != '0' && cub->map[y][x] != '2')
		return ;
	if (cub->map[y][x] == 'O' || cub->map[y][x] == 'X')
		return ;
	if (cub->map[y][x] == '0')
		cub->map[y][x] = 'O';
	if (y == (cub->height - 1) && (cub->map[y][x] == 'O'
		|| cub->map[y][x] == '2'))
		ft_exit(EXIT_FAILURE, cub, "Whole in the map\n");
	else if (cub->map[y][x] == '2')
		cub->map[y][x] = 'X';
	flood_check(cub, x + 1, y, overflow++);
	flood_check(cub, x - 1, y, overflow++);
	flood_check(cub, x, y + 1, overflow++);
	flood_check(cub, x, y - 1, overflow++);
	flood_check(cub, x + 1, y + 1, overflow++);
	flood_check(cub, x - 1, y - 1, overflow++);
	flood_check(cub, x + 1, y - 1, overflow++);
	flood_check(cub, x - 1, y + 1, overflow++);
}

void	parse_map(t_cub *cub)
{
	get_map(cub);
	check_map(cub);
	if (!ft_strchr("NSWE", cub->cp))
		ft_exit(EXIT_FAILURE, cub, "Wrong map\n");
	cub->map[cub->start.y][cub->start.x] = '0';
	flood_check(cub, cub->start.x, cub->start.y, 0);
	start_game(cub);
}
