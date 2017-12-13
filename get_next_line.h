/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: overetou <overetou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:43:37 by overetou          #+#    #+#             */
/*   Updated: 2017/12/12 16:27:21 by overetou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 45
# include "libft/includes/libft.h"
int get_next_line(int fd, char **line);

typedef struct	s_memory
{
	int				fd;
	char			cpy[BUFF_SIZE];
	struct s_memory	*next;
}				t_memory;

#endif
