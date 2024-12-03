# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUUFER_SIZE
# define BUFFER_SIZE 15
# endif 

char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
int	ft_strchr(const char *str, char c);
int ft_endline(const char *str);
char	*ft_strread(char *str, int fd);
char	*ft_str2(char *strva, char *str, int fd);
char	*ft_str1(char *str, int fd);
int	ft_strlen(const char *str);

# endif
