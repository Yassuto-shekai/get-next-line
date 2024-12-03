#include "get_next_line.h"

char	*ft_str1(char *str, int fd)
{
	str = malloc(BUFFER_SIZE);
	if (str == NULL)
		return (NULL);
	return (ft_strread(str, fd));
}

char	*ft_str2(char *strva, char *str, int fd)
{
		strva = malloc(ft_strlen(strva) + ft_strlen(str) + 1);
		if (strva == NULL)
			return (NULL);
		ft_strcpy(str, strva);
		free(strva);
		return (ft_strread(str, fd));
}

char	*ft_strread(char *str, int fd)
{
	int (j), (i);

	i = 0;
	j = 0;
	while (ft_endline(str) == 0 && j != 0)
	{
		j = read(fd, str, BUFFER_SIZE);
		i += j;
		if (j == 0 && i == 0)
			return (NULL);
		str[i] = '\0';
	}
	return (str);
}
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
