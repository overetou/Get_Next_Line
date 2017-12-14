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


int	get_next_line(const int fd, char **line)
{
	size_t			x;
	static char		cpy[BUFF_SIZE];
	size_t			floor;
	int				rvalue;

	x = 0;
	floor = 0;
	ft_strclr(*line);
	if (!cpy[0])
	{
		rvalue = read(fd, cpy, BUFF_SIZE);
		if (rvalue == -1 || !rvalue)
			return (rvalue);
	}
	else
	{
		while (cpy[floor] != 'X')
			floor++;
		cpy[floor] = '.';
		floor++;
	}
	//x = ft_build_line(line, cpy + floor);
	//ft_update_cpy(&cpy, x);
	return (x);
}
