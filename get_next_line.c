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

int	ft_pile(char **line, char *cpy)
{
	int		x;
	char	part[BUFF_SIZE];
	char	*to_delete;
	int 	y;

	x = 0;
	y = 0;
	while (cpy[x] != '\n' && cpy[x])
		x++;
	while (y < x)
	{
		part[y] = cpy[y];
		y++;
	}
	part[y] = '\0';
	to_delete = *line;
	if(!(*line = ft_strjoin(*line, part)))
		return (-1);
	ft_strdel(&to_delete);
	return (y);
}

int	ft_build_line(char *cpy, char **line, int y, int fd)
{
	int rvalue;
	int x;

	if (!(*line = ft_strnew(0)))
		return (-1);
	while (cpy[y] != '\n')
	{
		if ((x = ft_pile(line, cpy + y)) == -1)
			return (-1);
		y += x;
		if (!cpy[y])
		{
			rvalue = read(fd, cpy, BUFF_SIZE);
			ft_strclr(cpy + rvalue);
			ft_putstr("[");
			ft_putstr(cpy);
			ft_putstr("]");
			y = 0;
			if (!rvalue)
				return (0);
		}
	}
	if (!cpy[y + 1])
		return (0);
	return (y);
}

int	get_next_line(const int fd, char **line)
{
	static char		cpy[BUFF_SIZE];
	int				y;
	int				i;

	if (!(cpy[0]))
	{
		ft_putstr("!!");
		y = read(fd, cpy, BUFF_SIZE);
		ft_putstr(cpy);
		ft_putstr("]");
		if (y == -1 || !y)
			return (y);
		y = 0;
	}
	else
	{
		y = 0;
		while (cpy[y] != '\n' && cpy[y])
			y++;
		cpy[y++] = '.';
	}
	y = ft_build_line(cpy, line, y, fd);
	if (y == -1)
		return (-1);
	i = 0;
	while (i < y)
		cpy[i++] = '.';
	cpy[i] = '\0';
	return (1);
}
