# nasm  -f elf64 ft_strlen.s -o ft_strlen.o && ar rcs libasm.a *.o &&
# cc -g -o test test.c libasm.a && valgrind --leak-check=full -q ./test 

NAME	= 	libasm.a

SRCS	=	$(SRCDIR)/ft_strlen.s	$(SRCDIR)/ft_strcpy.s
SRCDIR	=	src

OBJS	=	$(SRCS:.s=.o)
OBJDIR	=	.obj

FLAGS	=	-f elf64 -g

$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	nasm $(FLAGS) -c $< -o $@

all:	$(OBJDIR) $(OBJS) $(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean:		clean
	rm -f $(NAME)

re:		fclean	all
