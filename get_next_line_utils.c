/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:55 by yel-mota          #+#    #+#             */
/*   Updated: 2024/11/24 16:24:53 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strread(char *dest, char *src,int fd, t_list *node)
{
	int j;

	j = 0;
	printf("ft_strread :  %s %s\n", dest, src)
	if (src == 0)
	{
		dest = malloc(BUFFER_SIZE + 1);
		if (dest == NULL)
			return (NULL);
		return (ft_read(dest, fd, node, j));
	}
	else 
	{
		j = ft_strlen(src);
		dest = malloc(j + BUFFER_SIZE + 1);
		if (dest == NULL)
			return (NULL);
		ft_strcpy(dest, src);
		printf("ft_strread p2 : %s %s\n", dest, src);
		free(src);
		return (ft_read(dest, fd, node, j));
	}
}

int	ft_islinenull(char *str)
{
	int	i;

	i = 0;
	printf("ft_islinenull : %s\n", str);
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}
