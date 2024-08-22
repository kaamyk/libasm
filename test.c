#include <string.h>
#include <stdio.h>

#include "test.h"

int	main( void )
{
	char	s[] = "bibi";
	char	t[5] = {0, 0, 0, 0, 0};
	char	r[] = "";

	printf("==================");
	printf("ft_strlen:\n");
	printf("len s: %ld\n", strlen(s));
	printf("len s: %ld\n", ft_strlen(s));
	printf("len t: %ld\n", strlen(t));
	printf("len t: %ld\n", ft_strlen(t));
	printf("len r: %ld\n", strlen(r));
	printf("len r: %ld\n", ft_strlen(r));

	return (0);
}