#ifndef	TEST
# define TEST

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

size_t	ft_strlen(char	*s);
char	ft_strcpy(char *dest, char *src);
int 	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, char *buf, size_t count);
ssize_t	ft_read(int fd, char *buf, size_t count);

#endif