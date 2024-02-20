NAME		= libftprintf.a

SRCS		= 	ft_printf.c\
				ft_putaddr_pf.c \
				ft_putchar_pf.c \
				ft_putnbr_pf.c \
				ft_putnbrbase_pf.c \
				ft_putstr_pf.c \
				ft_putunnbr_pf.c \
				ft_strlen_pf.c 

OBJS		= $(SRCS:%.c=$(PATH_COMP)%.o)
DEPS		=$(OBJS:%.o=%.d)
PATH_COMP	= ./.build/
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MP -MD
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

$(PATH_COMP)%.o:%.c ft_printf.h
	@if [ ! -d $(@D) ]; then mkdir $(@D); fi
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(PATH_COMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re