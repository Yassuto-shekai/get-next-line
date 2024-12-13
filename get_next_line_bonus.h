/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <yel-mota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:47:43 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/12 21:41:39 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strrest_bonus(char *str);
char	*ft_strline_bonus(char *str);
char	*ft_strread_bonus(int fd, char *dest);
char	*ft_strdup_bonus(const char *s);
char	*ft_strjoin_bonus(char const *s1, char const *s2);
size_t	ft_whereline_bonus(const char *str);
size_t	ft_strlen_bonus(const char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 77
# endif

#endif