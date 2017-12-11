#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 45

int get_next_line(int fd, char **line);

typedef struct	s_memory
{
	int		fd;
	char		cpy[BUFF_SIZE];
	struct s_memory	next;
}		t_memory;

typedef struct	s_mess
{
	int 		x;
	int 		y;
	int		floor;
	t_memory	head;
}		t_mess;

#endif
