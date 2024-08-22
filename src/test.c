#include <string.h>
#include <stdio.h>

#include "test.h"

#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define COLOR_RESET "\e[0m"


int	main( void )
{
	char	s[] = "bibi";
	char	t[5] = {0, 0, 0, 0, 0};
	char	r[] = "";

	char	buf1[255] = {0};
	char	buf2[255] = {0};

	printf("==================");
	printf("ft_strlen:\n");

	
	printf("strlen(s) / ft_strlen(s)\n");
	if (strlen(s) == ft_strlen(s))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len s: %ld\n", strlen(s));
		printf("len s: %ld\n", ft_strlen(s));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("strlen(t) / ft_strlen(t)\n");
	if (strlen(t) == ft_strlen(t))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len t: %ld\n", strlen(t));
		printf("len t: %ld\n", ft_strlen(t));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	
	printf("strlen(r) / ft_strlen(r)\n");
	if (strlen(r) == ft_strlen(r))
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("len r: %ld\n", strlen(r));
		printf("len r: %ld\n", ft_strlen(r));
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("==================");
	printf("ft_strcpy:\n");
	bzero(buf1, sizeof(buf1));
	strcpy(buf1, s);
	bzero(buf2, sizeof(buf2));
	ft_strcpy(buf2, s);

	if (strcmp(buf1, buf2) == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("strcpy: t(dest) == [%s]\n", buf1);
		printf("ft_strcpy: t(dest) == [%s]\n", buf2);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	return (0);
}