#include "inc/test.h"

int	errno_ft = 0;
int	errno_sys = 0;

void	test_strlen(char *str, char *s_empty, char *s_long)
{
	size_t	s1 = 0;
	size_t	s2 = 0;
	printf("==================\n");
	printf("ft_strlen:\n");

	
	printf("strlen(str) / ft_strlen(str)\n");
	s1 = strlen(str);
	s2 = ft_strlen(str);
	if (s1 == s2)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len s: %ld\n", strlen(str));
		printf("len s: %ld\n", ft_strlen(str));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strlen(s_empty) / ft_strlen(s_empty)\n");
	s1 = strlen(s_empty);
	s2 = ft_strlen(s_empty);
	if (s1 == s2)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len s_empty: %ld\n", strlen(s_empty));
		printf("len s_empty: %ld\n", ft_strlen(s_empty));
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

	printf("strlen(s_long) / ft_strlen(s_long)\n");
	s1 = strlen(s_long);
	s2 = ft_strlen(s_long);
	if (s1 == s2)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len r: %ld\n", strlen(s_long));
		printf("len r: %ld\n", ft_strlen(s_long));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
}

void	test_strcpy(char *str, char *s_empty, char *s_long)
{

	char	buf1[255] = {0};
	char	buf2[255] = {0};

	printf("==================\n");
	printf("ft_strcpy:\n");
	printf("strcpy(str) / ft_strcpy(str)\n");
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	strcpy(buf1, str);
	ft_strcpy(buf2, str);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: buf1(dest) == [%s]\n", buf1);
		printf("ft_strcpy: buf2(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strcpy(s_long) / ft_strcpy(s_long)\n");
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	strcpy(buf1, s_long);
	ft_strcpy(buf2, s_long);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: buf1(dest) == [%s]\n", buf1);
		printf("ft_strcpy: buf2(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strcpy(s_empty) / ft_strcpy(s_empty)\n");
	bzero(buf1, sizeof(buf1));
	bzero(buf2, sizeof(buf2));
	strcpy(buf1, s_empty);
	ft_strcpy(buf2, s_empty);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: buf1(dest) == [%s]\n", buf1);
		printf("ft_strcpy: buf2(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

}

void	test_strcmp(char *str, char *s_empty, char *s_long, char *s_long2)
{
	int		i1 = 0;
	int		i2 = 0;

	printf("==================\n");
	printf("ft_strcmp:\n");
	printf("strcmp(s_long, s_long2) / ft_strcmp(s_long, s_long2)\n");
	i1 = strcmp(s_long, s_long2);
	i2 = ft_strcmp(s_long, s_long2);
	printf("strcmp() == %d | ft_strcmp() == %d\n", i1, i2);
	if ((i1 == 0 && i2 == 0) || (i1 < 0 && i2 < 0) || (i1 > 0 && i2 > 0))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcmp: %d\n", strcmp(s_long, s_long2));
		printf("ft_strcmp: %d\n", ft_strcmp(s_long, s_long2));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}	

	printf("strcmp(s_long, str) / ft_strcmp(s_long, str)\n");
	i1 = strcmp(s_long, str);
	i2 = ft_strcmp(s_long, str);
	printf("strcmp() == %d | ft_strcmp() == %d\n", i1, i2);
	if ((i1 == 0 && i2 == 0) || (i1 < 0 && i2 < 0) || (i1 > 0 && i2 > 0))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcmp: %d\n", i1);
		printf("ft_strcmp: %d\n", i2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strcmp(s_empty, str) / ft_strcmp(s_empty, str)\n");
	i1 = strcmp(s_empty, str);
	i2 = ft_strcmp(s_empty, str);
	printf("strcmp() == %d | ft_strcmp() == %d\n", i1, i2);
	if ((i1 == 0 && i2 == 0) || (i1 < 0 && i2 < 0) || (i1 > 0 && i2 > 0))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcmp: %d\n", i1);
		printf("ft_strcmp: %d\n", i2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
}

void test_write(char *str, char *s_empty, char *s_long)
{
	printf("==================\n");
	remove("write_out");
	remove("ft_out");
	char	ft_res[256] = {0};
	char	res[256] = {0};

	ssize_t	bytes = 0;
	ssize_t	ft_bytes = 0;
	int	fd_sys = open("write_out", O_CREAT | O_RDWR, 777);
	printf("fd_sys == %d\n", fd_sys);
	if (fd_sys == -1)
	{
		printf("error %d: %s\n", errno, strerror(errno));
		printf("ft_sys failed\n");
		// return ;
	}
	int	fd_ft = open("ft_out", O_CREAT | O_RDWR, 777);
	printf("fd_ft == %d\n", fd_ft);
	if (fd_ft == -1)
	{
		printf("error %d: %s\n", errno, strerror(errno));
		close(fd_sys);
		// return ;
	}
	printf("write(str) / ft_write(str)\n");
	ft_bytes = ft_write(fd_ft, str, strlen(str));
	errno_ft = errno;
	if (errno)
		printf("(ft)error %d: %s\n", errno, strerror(errno));
	bytes = write(fd_sys, str, strlen(str));
	errno_sys = errno;
	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));

	bzero(res, 255);
	bzero(ft_res, 255);
	lseek(fd_sys, 0, SEEK_SET);
	lseek(fd_ft, 0, SEEK_SET);
	read(fd_sys, res, 255);
	read(fd_ft, ft_res, 255);

	if (strcmp(ft_res, res) == 0 && ft_bytes == bytes)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("fd_sys content: [%s](%ld bytes)\n", ft_res, ft_bytes);
		printf("fd_ft content: [%s](%ld bytes)\n", res, bytes);
		printf("errno_sys == %d | errno_ft == %d\n", errno_sys, errno_ft);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}	
	

	printf("write(s_empty) / ft_write(s_empty)\n");
	ft_bytes = ft_write(fd_ft, s_empty, strlen(s_empty));
	errno_ft = errno;
	if (errno)
		printf("(ft)error %d: %s\n", errno, strerror(errno));
	bytes = write(fd_sys, s_empty, strlen(s_empty));
	errno_sys = errno;
	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));
	

	bzero(res, 255);
	bzero(ft_res, 255);
	lseek(fd_sys, 0, SEEK_SET);
	lseek(fd_ft, 0, SEEK_SET);
	read(fd_sys, res, 255);
	read(fd_ft, ft_res, 255);

	if (strcmp(ft_res, res) == 0 && ft_bytes == bytes)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("fd_sys content: [%s](%ld bytes)\n", ft_res, ft_bytes);
		printf("fd_ft content: [%s](%ld bytes)\n", res, bytes);
		printf("errno_sys == %d | errno_ft == %d\n", errno_sys, errno_ft);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("write(s_long) / ft_write(s_long)\n");
	ft_bytes =ft_write(fd_ft, s_long, strlen(s_long));
	errno_ft = errno;
	if (errno)
		printf("(ft)error %d: %s\n", errno, strerror(errno));
	bytes =write(fd_sys, s_long, strlen(s_long));
	errno_sys = errno;
	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));

	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));

	bzero(res, 255);
	bzero(ft_res, 255);
	lseek(fd_sys, 0, SEEK_SET);
	lseek(fd_ft, 0, SEEK_SET);
	read(fd_sys, res, 255);
	read(fd_ft, ft_res, 255);

	if (strcmp(ft_res, res) == 0 && ft_bytes == bytes)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("fd_sys content: [%s](%ld bytes)\n", ft_res, ft_bytes);
		printf("fd_ft content: [%s](%ld bytes)\n", res, bytes);
		printf("errno_sys == %d | errno_ft == %d\n", errno_sys, errno_ft);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	close(fd_ft);
	close(fd_sys);
}

void	test_read()
{
	printf("==================\n");
	char	str[256] = {0};
	char	ft_str[256] = {0};

	ssize_t	bytes = 0;
	ssize_t	ft_bytes = 0;

	int	fd_sys = open("write_out", O_RDONLY, 777);
	printf("fd_ft == %d\n", fd_sys);
	if (fd_sys == -1)
	{
		printf("error %d: %s\n", errno, strerror(errno));
		printf("ft_sys failed\n");
		// return ;
	}
	int	fd_ft = open("ft_out", O_RDONLY, 777);
	printf("fd_ft == %d\n", fd_ft);
	if (fd_ft == -1)
	{
		printf("error %d: %s\n", errno, strerror(errno));
		printf("fd_ft failed\n");
		close(fd_sys);
		// return ;
	}

	printf("read() / ft_read()\n");

	bzero(str, 255);
	bzero(ft_str, 255);
	lseek(fd_sys, 0, SEEK_SET);
	lseek(fd_ft, 0, SEEK_SET);
	ft_bytes = ft_read(fd_ft, ft_str, 255);
	errno_ft = errno;
	if (errno)
		printf("(ft)error %d: %s\n", errno, strerror(errno));
	bytes = read(fd_sys, str, 255);
	errno_sys = errno;
	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));

	if (ft_strcmp(str, ft_str) == 0 && ft_bytes == bytes && errno_sys == errno_ft)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s](%ld bytes)\n", ft_str, ft_bytes);
		printf("str: [%s](%ld bytes)\n", str, bytes);
		printf("errno_sys == %d | errno_ft == %d\n", errno_sys, errno_ft);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("read(file_inexistant) / ft_read(file_inexistant)\n");

	bytes = read(55555, str, 255);
	errno_sys = errno;
	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));
	ft_bytes = ft_read(55555, ft_str, 255);
	errno_ft = errno;
	if (errno)
		printf("(ft)error %d: %s\n", errno, strerror(errno));

	if (ft_strcmp(str, ft_str) == 0 && ft_bytes == bytes && errno_sys == errno_ft)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s](%ld bytes)\n", ft_str, ft_bytes);
		printf("str: [%s](%ld bytes)\n", str, bytes);
		printf("errno_sys == %d | errno_ft == %d\n", errno_sys, errno_ft);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	ft_bytes = ft_read(-1, ft_str, 255);
	errno_ft = errno;
	if (errno)
		printf("(ft)error %d: %s\n", errno, strerror(errno));
	bytes = read(-1, str, 255);
	errno_sys = errno;
	if (errno)
		printf("error %d: %s\n", errno, strerror(errno));

	if (ft_strcmp(str, ft_str) == 0 && ft_bytes == bytes && errno_sys == errno_ft)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s](%ld bytes)\n", ft_str, ft_bytes);
		printf("str: [%s](%ld bytes)\n", str, bytes);
		printf("errno_sys == %d | errno_ft == %d\n", errno_sys, errno_ft);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
}

void	test_strdup(char *str, char *s_empty, char *s_long)
{
	(void) str;
	(void) s_empty;
	(void) s_long;
	char	*a = NULL;
	char	*b = NULL;
	void	*initial_brk = NULL;
	
	printf("==================\n");
	printf("strdup(str) / ft_strdup(str)\n");
	a = strdup(str);
	initial_brk = sbrk(0);
	b = ft_strdup(str);

	if ((a == NULL && b == NULL) || strcmp(a, b) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s]\n", a);
		printf("str: [%s]\n", b);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	if (a != NULL)
		free(a);
	if (brk(initial_brk) == -1)
	{
		perror("brk");
		exit (1);
	}

	printf("strdup(s_empty) / ft_strdup(s_empty)\n");
	a = strdup(s_empty);
	initial_brk = sbrk(0);
	b = ft_strdup(s_empty);

	if ((a == NULL && b == NULL) || strcmp(a, b) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s]\n", a);
		printf("str: [%s]\n", b);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	if (a != NULL)
		free(a);
	// if (b != NULL)
	// 	free(b);
	if (brk(initial_brk) == -1)
	{
		perror("brk");
		exit (1);
	}

	printf("strdup(s_long) / ft_strdup(s_long)\n");
	a = strdup(s_long);
	initial_brk = sbrk(0);
	b = ft_strdup(s_long);

	if ((a == NULL && b == NULL) || strcmp(a, b) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s]\n", a);
		printf("str: [%s]\n", b);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	if (a != NULL)
		free(a);
	// if (b != NULL)
	// 	free(b);
	if (brk(initial_brk) == -1)
	{
		perror("brk");
		exit (1);
	}




	struct rlimit old_limit;
	if (getrlimit(RLIMIT_AS,&old_limit) == -1)
	{
		perror("getrlimit()");
	}
	
	struct rlimit new_limit;
	
	new_limit.rlim_cur = 30 * 1024 * 1024;  // Soft limit (100 MB)
    new_limit.rlim_max = 30 * 1024 * 1024;  // Hard limit (100 MB)

	if (setrlimit(RLIMIT_AS, &new_limit) != 0) {
        perror("setrlimit");
        return ;
    }

	// int prlimit(pid_t pid, int resource,
			//    const struct rlimit *_Nullable new_limit,
			//    struct rlimit *_Nullable old_limit);
	// if (prlimit(getpid(), RLIMIT_AS, &new_limit, &old_limit) == -1)
	// {
	// 	perror("prlimit():");
	// }

	printf("(heap limited) strdup(s_long) / ft_strdup(s_long)\n");
	a = strdup(s_long);
	initial_brk = sbrk(0);
	b = ft_strdup(s_long);

	printf("a(%%p=[%p]) = [%s] \n b(%%p=[%p]) = [%s])", a,a,b,b);
	if ((a == NULL && b == NULL) || strcmp(a, b) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_str: [%s]\n", a);
		printf("str: [%s]\n", b);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	if (a != NULL)
		free(a);
	// if (b != NULL)
	// 	free(b);
	if (brk(initial_brk) == -1)
	{
		perror("brk");
		exit (1);
	}
	if (setrlimit(RLIMIT_AS, &old_limit) != 0) {
        perror("setrlimit");
        return ;
    }
}

void	test_atoi_base()
{
	int	res = 0;

	printf("==================\n");
	printf("ft_atoi_base(\"ABC\", NULL)\n");
	res = ft_atoi_base("ABC", NULL);			//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	printf("ft_atoi_base(\"ABC\", \"\")\n");
	res = ft_atoi_base("ABC", "");				//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	printf("ft_atoi_base(\"ABC\", \"a\")\n");
	res = ft_atoi_base("ABC", "a");				//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	printf("ft_atoi_base(\"ABC\", \"A BC\")\n");
	res = ft_atoi_base("ABC", "A BC");			//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	printf("ft_atoi_base(\"ABC\", \"A	BC\")\n");
	res = ft_atoi_base("ABC", "A	BC");		//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	printf("ft_atoi_base(\"ABC\", \"ABBC\")\n");
	res = ft_atoi_base("ABC", "ABBC");			//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"ABC\", \"ABC\")\n");
	res = ft_atoi_base("ABC", "ABC");			//
	if (res == 5)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"AAA\", \"ABC\")\n");
	res = ft_atoi_base("AAA", "ABC");			//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"666\", \"ABC\")\n");
	res = ft_atoi_base("666", "ABC");			//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"BAC\", \"ABC\")\n");
	res = ft_atoi_base("BAC", "ABC");			//
	if (res == 11)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"CAA\", \"ABC\")\n");
	res = ft_atoi_base("CAA", "ABC");			//
	if (res == 18)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	
	printf("ft_atoi_base(\"pui\", \"ppp\")\n");
	res = ft_atoi_base("", "ABC");			//
	if (res == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"pqqw\", \"qwertyuiop\")\n");
	res = ft_atoi_base("pqqw", "qwertyuiop");			//
	if (res == 9001)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_atoi_base(\"124556\", \"0123456789\")\n");
	res = ft_atoi_base("124556", "0123456789");			//
	if (res == 124556)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("res: [%d]\n", res);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
}

int	main( void )
{
	// char	str[] = "Bibi";
	char	*str = malloc(5);
	if (str == NULL)
		return(1);
	str[0] = 'B';
	str[1] = 'i';
	str[2] = 'b';
	str[3] = 'i';
	str[4] = '\0';
		
	char	s_empty[5] = {0};
	// char	*r = NULL;
	char	s_long[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque fringilla sapien lorem, a molestie massa consectetur eu. Suspendisse pulvinar ipsum convallis, accumsan nibh vitae, accumsan ex. In ullamcorper venenatis euismod. Vivamus a metus duis.";
	// char	s_long2[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque fringilla sapien lorem, a molestie massa consectetur eu. Suspendisse pulvinar ipsum convallis, accumsan nibh vitae, accumsan ex. In ullamcorper venenatis euismod. Vivamus a metus duis.";

	// test_strlen(str, s_empty, s_long);

	// test_strcpy(str, s_empty, s_long);

	// test_strcmp(str, s_empty, s_long, s_long2);

	// test_write(str, s_empty, s_long);

	// test_read(str, s_empty, s_long);

	test_strdup(str, s_empty, s_long);

	// test_atoi_base();

	free(str);
	return (0);
}