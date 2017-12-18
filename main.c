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

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int rvalue;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	rvalue = get_next_line(fd, &line);
	ft_putendl(line);
	ft_strdel(&line);
	ft_putnbr(rvalue);
	ft_putchar('\n');
	rvalue = get_next_line(fd, &line);
	ft_putnbr(rvalue);
	//while ((rvalue = get_next_line(fd, &line)))
	//{
	//	ft_putendl(line);
	//	ft_strdel(&line);
	//}
	//ft_putnbr(rvalue);
	//ft_putchar('\n');
	close(fd);
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
