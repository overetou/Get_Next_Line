void	ft_lst_to_str(char **line, t_list stock)
{

}

static t_memory	*ft_search_fd(int fd, t_memory **memory)
{
	t_memory *new;

	if (!(*memory))
	{
		(*memory) = (t_memory*)malloc(sizeof(t_memory));
		(*memory)->next = NULL;
	}
	while ((*memory)->next)
	{
		if ((*memory)->fd == fd)
			return ((*memory));
		(*memory) = (*memory)->next;
	}
	new = (t_memory*)malloc(sizeof(t_memory));
	new->next = NULL;
	(*memory)->next = new;
	return (new);
}

int				ft_make_line(int floor, t_memory **head, **line)
{
	int		x;
	int		y;
	t_list	*stock;

	x = 0;
	y = 0;
	while ((*head)->cpy[floor + x] != '\n')
	{
		x = 0;
		while ((*head)->cpy[x + floor] != '\n' && (*head)->cpy[x + floor])
			ft_lstadd(stock, ft_lstnew(cpy[floor + x++], 1));
		y += x;
		if (!(*head)->cpy[x + floor])
		{
			rvalue = read(fd, (*head)->cpy, BUFF_SIZE);
			if (rvalue == 0 || rvalue == -1)
			{
				ft_memory_del(head);
				return (rvalue);
			}
			floor = 0;
		}
		*line = ft_strnew(y);
		ft_lst_to_str(line, stock);
		//ft_lstdel(stock);
	}
}

int				get_next_line(int fd, char **line)
{
	static t_memory	*memory;
	int				rvalue;
	t_memory		*head;
	int				floor;

	floor = 0;
	head = ft_search_fd(fd, &memory);
	if (head->cpy == 0)
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
	ft_make_line(floor, head, line);
}
