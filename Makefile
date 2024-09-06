
NAME	= 	libasm.a

SRCDIR	=	src
SRCS	=	$(SRCDIR)/ft_strlen.s	$(SRCDIR)/ft_strcpy.s	$(SRCDIR)/ft_strcmp.s	\
			$(SRCDIR)/ft_write.s	$(SRCDIR)/ft_read.s		$(SRCDIR)/ft_strdup.s	\
			$(SRCDIR)/ft_atoi_base_bonus.s	$(SRCDIR)/ft_list_push_front_bonus.s	\
			$(SRCDIR)/ft_list_size_bonus.s	$(SRCDIR)/ft_list_sort_bonus.s			

OBJDIR	=	.obj
OBJS	=	$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(SRCS))

B_OBJS	=	$(patsubst $(SRCDIR)/%.s, $(OBJDIR)/%.o, $(B_SRCS))


COMPIL	=	nasm

FLAGS	=	-felf64 -g -F dwarf -DPIC

all:	$(OBJDIR) $(OBJS) $(NAME)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(COMPIL) $(FLAGS) $< -o $@

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:		$(OBJDIR) $(OBJS) $(B_OBJS)
	ar rcs $(NAME) $(B_OBJS) $(OBJS)

clean:
	rm -rf $(OBJDIR)

fclean:		clean
	rm -f $(NAME)

re:		fclean	all
