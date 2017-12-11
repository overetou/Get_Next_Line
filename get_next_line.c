int	get_next_line(int fd, char **line)
{
	static t_memory	*memory;
	int		rvalue;
	t_mess		mess;

	mess.head = ft_search_fd(fd, memory); //la fonction renvoie la liste contenant le fd donné ou l'adresse d'un nouveau maillon qui le contiendra
	if (mess.head->cpy == 0)
	{
		rvalue = read(fd, mess.head->cpy, BUFF_SIZE);
		if (rvalue == 0 || rvalue == -1)
			return (rvalue);
	}
	else
	{
		while (mess.head->cpy != '\0')
			floor++;
		mess.head->cpy[floor++] = '\n';
	}
}
