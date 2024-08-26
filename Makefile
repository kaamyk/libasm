
NAME	= 	libasm.a

SRCDIR	=	src
SRCS	=	$(SRCDIR)/ft_strlen.s	$(SRCDIR)/ft_strcpy.s

OBJDIR	=	.obj
OBJS	=	$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SRCS))

COMPIL	=	nasm

FLAGS	=	-f elf64 -g

all:	$(OBJDIR) $(OBJS) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(COMPIL) $(FLAGS) $< -o $@

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean:		clean
	rm -f $(NAME)

re:		fclean	all
