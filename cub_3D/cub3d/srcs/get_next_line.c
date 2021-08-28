/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoppin <echoppin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:17:41 by echoppin          #+#    #+#             */
/*   Updated: 2021/06/27 15:40:24 by echoppin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	get_size(int c, char *save)
{
	int	i;

	i = 0;
	while (save[i] && save[i] != c)
		i++;
	if (save[i] == c)
		return (i);
	return (-1);
}

void	get_sub_save(int start, char *save, char **line, char *dest)
{
	int		i;
	int		size;
	char	*temp;

	*line = dest;
	size = ft_strlen(save);
	i = 0;
	while (save[i] && start--)
		i++;
	temp = ft_strndup(save + i + 1, size);
	ft_strncpy(save, temp, size);
	free(temp);
}

int	get_file(int fd, char *save)
{
	int	readfile;

	if (read(fd, &readfile, 0) == -1)
		return (0);
	readfile = 1;
	if (!save[0])
		ft_bzero(save, STACK_SIZE + BUFFER_SIZE);
	while (readfile > 0 && get_size('\n', save) == -1)
		readfile = read(fd, &save[ft_strlen(save)], BUFFER_SIZE);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	save[STACK_SIZE + BUFFER_SIZE];
	int			size;
	int			ret;
	char		*dest;

	ret = 1;
	if (!get_file(fd, save) || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	size = get_size('\n', save);
	if (size == -1)
	{
		size = ft_strlen(save);
		ret = 0;
	}
	if (save[0])
		dest = ft_strndup(save, size);
	else
	{
		dest = malloc(1);
		if (!(dest))
			return (-1);
		dest[0] = '\0';
	}
	get_sub_save(size, save, line, dest);
	return (ret);
}
