#include "inc/test.h"

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

	printf("ft_atoi_base(NULL, \"ABC\")\n");
	res = ft_atoi_base(NULL, "ABC");			//
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

	printf("ft_atoi_base(\"ABC\", \"A\")\n");
	res = ft_atoi_base("ABC", "A");				//
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

	printf("ft_atoi_base(\"ABC\", \"A\\tBC\")\n");
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
	res = ft_atoi_base("pui", "ppp");			//
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

void	free_list(t_list *l)
{
	t_list	*tmp = NULL;
	while (l != NULL)
	{
		free(l->data);
		tmp = l;
		l = l->next;
		free(tmp);
	}
}

void	free_list_n(t_list *l)
{
	t_list	*tmp = NULL;
	while (l != NULL)
	{
		tmp = l;
		l = l->next;
		free(tmp);
	}
}

void	print_list(t_list *l)
{
	if (l == NULL)
	{
		printf("List is empty\n");
		return ;
	}
	
	t_list	*tmp = l;
	for (int i = 0; tmp != NULL; i++)
	{
		printf("item[%d]->data == [%s]\n", i, (char*)tmp->data);
		tmp = tmp->next;
	}
}

void	print_list_n(t_list *l)
{
	if (l == NULL)
	{
		printf("List is empty\n");
		return ;
	}
	
	t_list	*tmp = l;
	for (int i = 0; tmp != NULL; i++)
	{
		printf("item[%d]->data(%p) == [%d]\n", i, &(tmp->data), *(int*)tmp->data);
		printf("item[%d]->next == %p\n", i, tmp->next);
		tmp = tmp->next;
	}
}

void	test_list_push_front()
{
	printf("==================\n");
	printf("ft_list_push_front(valid) / ft_list_push_front(valid)\n");

	char	*s = malloc(2);
	s[0] = 'A';
	s[1] = '\0';
	t_list	*l = malloc(sizeof(t_list));
	if (l == NULL)
		return ;
	l->data = strdup(s);
	l->next = NULL;
	t_list	*prev = l;
	t_list	*n_l = NULL;

	for (int i = 0; i < 3; i++)
	{
		n_l = malloc(sizeof(t_list));
		(*s)++;
		n_l->data = strdup(s);
		n_l->next = NULL;

		prev->next = n_l;
		prev = n_l;
		n_l = n_l->next;
	}
	prev = l;
	print_list(prev);

	(*s)++; // s[0] = 'D'

	printf("Before l addr == %p\n", l);
	ft_list_push_front(&l, s);
	printf("After l addr == %p\n", l);

	prev = l;
	print_list(prev);

	if (l != NULL && l->data != NULL && strcmp (l->data, s) == 0 && l->next != NULL)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("l: [%p]\n", l);
		printf("l->data: [%p]\n", l->data);
		printf("l->next: [%p]\n", l->next);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_list_size(valid) / ft_list_size(valid)\n");
	int	a = ft_list_size(l);
	if (a == 5)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_len == %d\n", a);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	
	free_list(l);
	printf("\n");

	printf("ft_list_push_front(NULL, valid) / ft_list_push_front(NULL, valid)\n");

	s = malloc(4);
	s[0] = 'L';
	s[1] = 'O';
	s[2] = 'L';
	s[3] = '\0';
	
	l = NULL;
	prev = l;
	print_list(prev);

	printf("Before l addr == %p\n", l);
	ft_list_push_front(&l, s);
	printf("After l addr == %p\n", l);

	prev = l;
	print_list(prev);

	if (l != NULL && l->data != NULL && strcmp(l->data, s) == 0 && l->next == NULL)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("l: [%p]\n", l);
		printf("l->data: [%p]\n", l->data);
		printf("l->next: [%p]\n", l->next);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_list_size(single) / ft_list_size(single)\n");
	a = ft_list_size(l);
	if (a == 1)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_len == %d\n", a);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}
	
	printf("\n");
	free_list(l);

	printf("ft_list_push_front(NULL, NULL) / ft_list_push_front(NULL, NULL)\n");
	s = NULL;
	l = NULL;
	prev = l;
	print_list(prev);

	printf("Before l addr == %p\n", l);
	ft_list_push_front(&l, s);
	printf("After l addr == %p\n", l);

	prev = l;
	print_list(prev);

	if (l != NULL && l->data == NULL && l->next == NULL)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("l: [%p]\n", l);
		printf("l->data: [%p]\n", l->data);
		printf("l->next: [%p]\n", l->next);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("ft_list_size(NULL) / ft_list_size(NULL)\n");
	a = ft_list_size(NULL);
	if (a == 0)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("ft_len == %d\n", a);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("\n");
	free_list(l);

	printf("ft_list_push_front(valid, int*) / ft_list_push_front(valid, int*)\n");

	int		n[] = {42, 43, 44, 45, 46};

	l = malloc(sizeof(t_list));
	if (l == NULL)
		return ;
	l->data = n;
	l->next = NULL;
	prev = l;
	n_l = NULL;

	for (int i = 0; i < 3; i++)
	{
		n_l = malloc(sizeof(t_list));
		n_l->data = n + (i + 1);
		n_l->next = NULL;

		prev->next = n_l;
		prev = n_l;
		n_l = n_l->next;
	}
	prev = l;
	print_list_n(prev);


	printf("Before l addr == %p\n", l);
	ft_list_push_front(&l, n + 4);
	printf("After l addr == %p\n", l);

	prev = l;
	print_list_n(prev);

	if (l != NULL && l->data != NULL && l->next != NULL)
		printf(GRN ">>> OK <<<\n" COLOR_RESET);
	else
	{
		printf("l: [%p]\n", l);
		printf("l->data: [%p]\n", l->data);
		printf("l->next: [%p]\n", l->next);
		printf(RED ">>> KO <<<\n" COLOR_RESET);
	}

	printf("\n");
	free_list_n(l);
}

int	main( void )
{
	test_atoi_base();
	test_list_push_front();
}