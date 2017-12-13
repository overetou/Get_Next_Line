/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:42:52 by overetou          #+#    #+#             */
/*   Updated: 2017/12/12 20:42:19 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_memory_del(t_memory **head, char **line)
{
	t_memory *next;

	ft_strclr(*line);
	next = (*head)->next;
	free(*head);
	*head = next;
}

int		ft_lst_to_str(char **line, t_list **stock, int y)
{
	int		x;
	t_list	*head;

	x = 0;
	head = (*stock)->next;
	*line = ft_strnew(y + 1);
	while (head)
	{
		ft_memcpy((void*)*line + x++, head->content, 1);
		head = head->next;
	}
	while(*stock)
	{
		head = (*stock)->next;
		free((*stock)->content);
		free(*stock);
		*stock = head;
	}
	stock = NULL;
	return (1);
}

static t_memory	*ft_search_fd(int fd, t_memory **memory)
{
	t_memory *new;

	
	if (!(*memory))
	{
		(*memory) = (t_memory*)malloc(sizeof(t_memory));
		(*memory)->next = NULL;
		(*memory)->fd = fd;
	}
	while ((*memory))
	{
		if ((*memory)->fd == fd)
			return ((*memory));
		(*memory) = (*memory)->next;
	}
	new = (t_memory*)malloc(sizeof(t_memory));
	new->next = NULL;
	new->fd = fd;
	(*memory)->next = new;
	return (new);
}

int				ft_make_line(int floor, t_memory **head, char **line, int fd)
{
	int		x;
	int		y;
	t_list	*stock;
	int		rvalue;

	x = 0;
	y = 0;
	stock = ft_lstnew((void*)(*head)->cpy + floor, 1);
	while ((*head)->cpy[floor + x] != '\n')
	{
		x = 0;
		while ((*head)->cpy[x + floor] != '\n' && (*head)->cpy[x + floor])
			ft_lstaddnext(stock, ft_lstnew((void*)(*head)->cpy + floor + x++, 1));
		y += x;
		if (!(*head)->cpy[x + floor])
		{
			rvalue = read(fd, (*head)->cpy, BUFF_SIZE);
			if (rvalue == 0 || rvalue == -1)
			{
				ft_memory_del(head, line);
				return (rvalue);
			}
			floor = 0;
		}
	}
	x = 0;
	while (x != y)
		(*head)->cpy[x++ + floor] = '\n';
	(*head)->cpy[x + floor] = '\0';
	return	(ft_lst_to_str(line, &stock, y));
}

int				get_next_line(int fd, char **line)
{
	static t_memory	*memory;
	int				rvalue;
	t_memory		*head;
	int				floor;

	floor = 0;
	head = ft_search_fd(fd, &memory);
	if (!head->cpy[0])
	{
		rvalue = read(fd, head->cpy, BUFF_SIZE);
		if (rvalue == 0 || rvalue == -1)
			return (rvalue);
	}
	else
	{
		floor = ft_strchr(head->cpy, '\0') - head->cpy;
		head->cpy[floor++] = '\n';
	}
	return (ft_make_line(floor, &head, line, fd));
}
