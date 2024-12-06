/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:09 by yel-mota          #+#    #+#             */
/*   Updated: 2024/12/06 15:10:54 by yel-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(const char *str)
{
        char    *dest;

        dest = malloc(sizeof(int) * ft_strlen(str) + 1);
        if (dest == NULL)
                return (NULL);
        while (*str != '\0')
        {
                *dest = *str;
                str++;
                dest++;
        }
        return (*dest = '\0', dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *str;
        size_t  i;
        size_t  j;

        if (s1 == NULL || s2 == NULL)
                return (NULL);
        i = 0;
        str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
        if (str == NULL)
                return (NULL);
        while (s1[i] != '\0')
        {
                str[i] = s1[i];
                i++;
        }
        j = 0;
        while (s2[j] != '\0')
        {
                str[i] = s2[j];
                i++;
                j++;
        }
        str[i] = '\0';
        return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}
