/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:31:22 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/06 15:32:00 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char    *get_next_line(int fd);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strread(int fd, char *dest);
char    *ft_strdup(const char *str);
char     *ft_whereline(char *dest);
int    ft_strline(const char *str);
size_t     ft_strlen(const char *str);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 40
# endif

#endif
