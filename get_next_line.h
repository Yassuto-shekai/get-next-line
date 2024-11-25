/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:37:48 by yel-mota          #+#    #+#             */
/*   Updated: 2024/11/23 21:40:28 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

typedef struct s_list 
{
	int newline;
	int endofile;

}	t_list;

char	*ft_strread(char *dest, char *src, int fd, t_list *node);
int	ft_islinenull(char *str);
char *get_next_line(int fd);
char	*ft_read(char *src, int fd, t_list *node, int i);
char	*ft_strcpy(char *dest, const char *src);
size_t ft_strlen(const char *str);
int     ft_strchr(const char *src, int chr, t_list *node);

#endif
