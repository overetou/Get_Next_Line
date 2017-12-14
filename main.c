/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 05:26:42 by jrameau           #+#    #+#             */
/*   Updated: 2017/12/13 17:26:44 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int ft_build_line(char **line, char *cpy)
{
	int x;
	char part[BUFF_SIZE];
	char *to_delete;

	x = 0;
	*line = ft_strnew(0);
	while (cpy[x] != '\n')
	{
		x = 0;
		while (cpy[x] != '\n' && cpy[x])
			x++;		
		ft_strncpy(part, cpy, x);
		part[x] = '\0';
		to_delete = *line;
		*line = ft_strjoin(*line, part);
		ft_strdel(&to_delete);
	}
	return (0);
}

int main(void)
{
	char *line;
	char cpy[] = "ca roule ?\n Coucou";

	ft_build_line(&line, cpy);
	ft_putendl(line);
	return (0);
}

//int		main(int argc, char **argv)
//{
//	int		fd;
//	char	*line;
//	int		rvalue;
//
//	if (argc == 1)
//		fd = 0;
//	else if (argc == 2)
//		fd = open(argv[1], O_RDONLY);
//	else
//		return (2);
//	while ((rvalue = get_next_line(fd, &line)) == 1)
//	{
//		ft_putendl(line);
//		ft_putnbr(rvalue);
//		ft_putchar('\n');
//		free(line);
//	}
//	if (argc == 2)
//		close(fd);
//	return (0);
//}
