NAME		= libft.a

SRCS		= \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_isprint.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_memchr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_vector_add.c \
			ft_vector_init.c \
			ft_vector_resize.c \
			ft_new_tree.c \
			ft_join_tree.c


OBJS		= $(SRCS:%.c=$(PATH_COMP)%.o)
DEPS		= $(OBJS:%.o=%.d)
PATH_COMP	= ./.build/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MP -MMD
RM			= rm -rf
PATH_PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(PATH_PRINTF)
	cp $(PATH_PRINTF) $(NAME)
	ar -rs $(NAME) $(OBJS)

$(PATH_PRINTF): FORCE
	$(MAKE) -C ft_printf

$(PATH_COMP)%.o:%.c
	@if [ ! -d $(@D) ]; then mkdir $(@D); fi
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(PATH_COMP)
	$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
		$(MAKE) -C ft_printf fclean


re: fclean all

FORCE :

.PHONY: all clean fclean re FORCE