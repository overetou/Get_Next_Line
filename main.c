#include "get_next_line.h"
#include "fcntl.h"

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	//int 	rvalue;

	(void)argc;
	fd = (open(argv[1], O_RDONLY));
	//while ((rvalue = get_next_line(fd, &line)) > 0)
	//{
	//	ft_putstr(line);
	//	ft_putchar('\n');
	//	ft_putnbr(rvalue);
	//}a
	get_next_line(fd, &line);
	ft_putstr(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	get_next_line(fd, &line);
	ft_putstr(line);
	return (0);
}

