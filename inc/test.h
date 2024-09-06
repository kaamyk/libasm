#ifndef	TEST
# define TEST

#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/resource.h>

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"

typedef struct	s_list
{
	void	*data;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(char	*s);
char	*ft_strcpy(char *dest, char *src);
int 	ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, char *buf, size_t count);
ssize_t	ft_read(int fd, char *buf, size_t count);
char	*ft_strdup(char *src);

//	BONUS
int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
int	*ft_list_sort(t_list **begin_list, int (*cmp)());

#endif