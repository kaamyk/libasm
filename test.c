#include "inc/test.h"

void	test_strlen(char *s, char *t, char *l)
{
	size_t	s1 = 0;
	size_t	s2 = 0;
	printf("==================\n");
	printf("ft_strlen:\n");

	
	printf("strlen(s) / ft_strlen(s)\n");
	s1 = strlen(s);
	s2 = ft_strlen(s);
	if (s1 == s2)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len s: %ld\n", strlen(s));
		printf("len s: %ld\n", ft_strlen(s));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strlen(t) / ft_strlen(t)\n");
	s1 = strlen(t);
	s2 = ft_strlen(t);
	if (s1 == s2)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len t: %ld\n", strlen(t));
		printf("len t: %ld\n", ft_strlen(t));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	
	// printf("strlen(r) / ft_strlen(r)\n");
	// s1 = strlen(r);
	// s2 = ft_strlen(r);
	// if (s1 == s2)
	// 	printf(GRN ">>> OK <<<\n" COLOR_RESET);
	// else
	// {
	// 	printf("len r: %ld\n", strlen(r));
	// 	printf("len r: %ld\n", ft_strlen(r));
	// 	printf(RED ">>> KO <<<\n" COLOR_RESET);
	// }

	printf("strlen(l) / ft_strlen(l)\n");
	s1 = strlen(l);
	s2 = ft_strlen(l);
	if (s1 == s2)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len r: %ld\n", strlen(l));
		printf("len r: %ld\n", ft_strlen(l));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
}

void	test_strcpy(char *s, char *t, char *l)
{

	char	buf1[255] = {0};
	char	buf2[255] = {0};

	printf("==================\n");
	printf("ft_strcpy:\n");
	printf("strcpy(s) / ft_strcpy(s)\n");
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	strcpy(buf1, s);
	ft_strcpy(buf2, s);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: buf1(dest) == [%s]\n", buf1);
		printf("ft_strcpy: buf2(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strcpy(l) / ft_strcpy(l)\n");
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	strcpy(buf1, l);
	ft_strcpy(buf2, l);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: buf1(dest) == [%s]\n", buf1);
		printf("ft_strcpy: buf2(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strcpy(t) / ft_strcpy(t)\n");
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	strcpy(buf1, t);
	ft_strcpy(buf2, t);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: buf1(dest) == [%s]\n", buf1);
		printf("ft_strcpy: buf2(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

}

void	test_strcmp(char *s, char *t, char *l, char *l2)
{
	int		i1 = 0;
	int		i2 = 0;

	printf("==================\n");
	printf("ft_strcmp:\n");
	printf("strcmp(l, l2) / ft_strcmp(l, l2)\n");
	i1 = strcmp(l, l2);
	i2 = ft_strcmp(l, l2);
	if ((i1 == 0 && i2 == 0) || (i1 < 0 && i2 < 0) || (i1 > 0 && i2 > 0))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcmp: %d\n", strcmp(l, l2));
		printf("ft_strcmp: %d\n", ft_strcmp(l, l2));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}	

	printf("strcmp(l, s) / ft_strcmp(l, s)\n");
	i1 = strcmp(l, s);
	i2 = ft_strcmp(l, s);
	if ((i1 == 0 && i2 == 0) || (i1 < 0 && i2 < 0) || (i1 > 0 && i2 > 0))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcmp: %d\n", i1);
		printf("ft_strcmp: %d\n", i2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strcmp(t, s) / ft_strcmp(t, s)\n");
	i1 = strcmp(t, s);
	i2 = ft_strcmp(t, s);
	if ((i1 == 0 && i2 == 0) || (i1 < 0 && i2 < 0) || (i1 > 0 && i2 > 0))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcmp: %d\n", i1);
		printf("ft_strcmp: %d\n", i2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
}

void test_write(char *s, char *t)
{
	(void)t;
	int	fd_ft = open("ft_write_out.txt", O_CREAT, S_IRWXU);
	if (fd_ft == -1)
	{
		printf("fd_ft failed\n");
		return ;
	}
	int	fd_sys = open("write_out.txt", O_CREAT, S_IRWXU);
	if (fd_sys == -1)
	{
		printf("ft_sys failed\n");
		close(fd_ft);
		return ;
	}
	for (int i = 0; *(s + i) != 0; i++)
	{
		printf("&s == %p\n", s+i);
	}
	ft_write(fd_ft, s, strlen(s));
	write(fd_sys, s, strlen(s));

	close(fd_ft);
	close(fd_sys);
}

int	main( void )
{
	char	s[] = "Bibi";
	char	t[5] = {0};
	// char	*r = NULL;
	// char	l[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque fringilla sapien lorem, a molestie massa consectetur eu. Suspendisse pulvinar ipsum convallis, accumsan nibh vitae, accumsan ex. In ullamcorper venenatis euismod. Vivamus a metus duis.";
	// char	l2[] = "dorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque fringilla sapien lorem, a molestie massa consectetur eu. Suspendisse pulvinar ipsum convallis, accumsan nibh vitae, accumsan ex. In ullamcorper venenatis euismod. Vivamus a metus duis.";

	// test_strlen(s, t, l);

	// test_strcpy(s, t, l);

	// test_strcmp(s, t, l, l2);

	test_write(s, t);

	return (0);
}