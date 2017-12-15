/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:42:52 by overetou          #+#    #+#             */
/*   Updated: 2017/12/13 18:01:21 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

int ft_pile(char **line, char *cpy)
{
	int x;
	char part[BUFF_SIZE];
	char *to_delete;

	x = 0;
	if (!(*line))
	{
		if (!(*line = ft_strnew(0)))
			return (-1);
	}
	while (cpy[x] != '\n' && cpy[x])
		x++;
	ft_strncpy(part, cpy, x);
	part[x] = '\0';
	to_delete = *line;
	*line = ft_strjoin(*line, part);
	ft_strdel(&to_delete);
	return (x);
}

int ft_build_line(char *cpy, char **line, int y, int fd)
{
	int rvalue;
	int x;

	rvalue = 1;
	while (cpy[y] != '\n' && rvalue)
	{
		if ((x = ft_pile(line, cpy + y)) == -1)
			return (-1);
		y += x;
		if (!cpy[y])
		{
			rvalue = read(fd, cpy, BUFF_SIZE);
			ft_strclr(cpy + rvalue);
			y = 0;
		}
	}
	return (y);
}

int	get_next_line(const int fd, char **line)
{
	static char		cpy[BUFF_SIZE];
	int				y;

	*line = NULL;
	if (!(cpy[0]))
	{
		y = read(fd, cpy, BUFF_SIZE);
		if (y == -1 || !y)
			return (y);
		y = 0;
	}
	else
	{
		cpy[(y = ft_strchr(cpy, 'x') - cpy)] = '.';
		y++;
	}
	y = ft_build_line(cpy, line, y, fd);
	if (y == -1)
		return (-1);
	return (1);
}
