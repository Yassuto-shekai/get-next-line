/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:37:48 by yel-mota          #+#    #+#             */
/*   Updated: 2024/11/24 15:02:17 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strchr(const char *src, int chr, t_list *node)
{
        int             i;

        i = 0;
        while (src[i] != (char)chr)
        {
                if (src[i] == '\0')
                        return (-1);
                i++;
        }
	if (src[i] == chr)
		node->newline = 1;
        return (i);
}

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	m;

	m = 0;
	while (src[m] != '\0')
	{
		dest[m] = src[m];
		m++;
	}
		dest[m] = '\0';
	return (dest);
}

char	*ft_read(char *dest, int fd, t_list *node, int j)
{
	int (i), (n);

	i = 0;
	n = 1;
	node->endofile = 0;
	while (ft_islinenull(dest) == 1 && n != 0)
	{
		n = read(fd, dest + i + j, BUFFER_SIZE);
		i = i + n;
		if (i == 0 && n == 0)
			return (NULL);
		if (n == 0)
			node->endofile = 1;
	}
	if (i > 0)
		dest[i + j] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	static char *dest;
	char *str;
	int (i), (j);
	t_list *node;

	ft_strread(str, dest, fd, node);
	node = malloc(sizeof(t_list));
	if (str == NULL)
	{
		free(node);
		return (NULL);
	}
	if (node->newline == 0 && node->endofile == 1)
	{
		free(node);
		return (str);
	}
	i = ft_strchr(str, '\n', node) + 1;
	j = ft_strlen(str) - i - 1;
	dest = malloc(j + 2);
	if (dest == NULL)
	{
		free(node);
		return (NULL);
	}
	if (node->endofile == 0)
	ft_strcpy(dest, str + i);
	str[i] = '\0';
	free(node);
	return (str);
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s", str);
		str = get_next_line(fd);
		free(str);
	}
	close (fd);
	return (0);
}
