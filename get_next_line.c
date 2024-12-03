#include "get_next_line.h"
int ft_endline(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strchr(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*dest;
	char	*str;
	int	(i), (j);

	str = NULL;
	if (dest == NULL)
		str = ft_str1(str, fd);
	else
		str = ft_str2(dest, str, fd);
	if (str == NULL)
		return (NULL);
	i = ft_strlen(str);
	if (ft_endline(str))
	{
		j = ft_strchr(str, '\n');
		printf("\nget 3 : %s", str);
		if (j == -1)
			return (NULL);
		if (j == i)
			return (str);
		dest = malloc(i - j + 1);
		if (dest == NULL)
			return (NULL);
		ft_strcpy(dest, str + j);
		printf("\nget 4 : %s", str);
		str[j + 1] = '\0';
	}	
	printf("\nget 2 : %s %s", str, dest);
	return (str);
}
int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *str;
	int i = 0;
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("\n%s", str);
		i++;
	}
	free(str);
	close(fd);
	return (0);
}
