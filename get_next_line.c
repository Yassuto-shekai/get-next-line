/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:28:15 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/06 16:44:19 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strline(const char *str)
{
	while (*str != '\n')
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strread(int fd, char *dest)
{
	ssize_t	(i);
	size_t	(r);
	char	(*str), (*tmp);

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	if (!dest)
		dest = ft_strdup("");
	r = 0;
	while (ft_strline(str) == 0 && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		r += i;
		if (i == 0 && r == 0)
			return (NULL);
		str[i] = '\0';
		tmp = dest;
		dest = ft_strjoin(tmp, str);
		free(tmp);
	}
	free(str);
	return (dest);
}

char	*ft_whereline(char *dest)
{
	size_t	i;
	char	*str;

	i = 0;
	if (ft_strline(dest) == 0)
		return (dest);
	while (dest[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (dest[i - 1] != '\n')
	{
		str[i] = dest[i];
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}

char	*ft_strrest(char *dest)
{
	size_t	(i), (j), (r);
	char	*str;

	if (ft_strline(dest) == 0)
		return (ft_strdup(""));
	j = ft_strlen(dest);
	while (dest[i - 1] != '\n')
		i++;
	str = malloc(j - i + 1);
	if (str == NULL)
		return (NULL);
	r = 0;
	while (dest[i + r] != '\0')
	{
		str[r] = dest[i + r];
		r++;
	}
	str[r] = '\0';
	free(dest);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*dest;
	char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dest = ft_strread(fd, dest);
	if (!dest)
		return (NULL);
	str = ft_whereline(dest);
	dest = ft_strrest(dest);
	return(str);
}
