include ../libft/comp/color.mk

FLAGS = -Wall -Wextra -Werror -c -MMD -MP

NAME = libftprintf.a

SRC = ./srcs/ft_printaddress.c \
	  ./srcs/ft_strlen.c \
	  ./srcs/ft_putnbr_base.c \
	  ./srcs/ft_putchar.c \
	  ./srcs/ft_putnbr.c \
	  ./srcs/ft_putstr.c \
	  ./srcs/ft_printf.c

all: $(NAME)

OBJ_DEP = $(OBJ:.o=.d)

OBJ = $(SRC:.c=.o)

-include $(OBJ_DEP)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
	@echo "🔗 $(GREEN)> $(YELLOW)ar $(RED)-rc $(GREEN)$(NAME)$(END) $(OBJS)"
	@echo "📚 $(CYAN)libpintf done\n$(END)"

%.o:%.c ./header/ft_printf.h
	@$(CC) $(FLAGS) -o $@ -c $< -I header
	@echo "🔧 $(GREEN)> $(YELLOW)$(CC) $(RED)$(FLAGS) $(END)-o $@ -c $< $(GRAY)-I header$(END)"

clean: 
	@rm -f $(OBJ) $(OBJ_DEP)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean bonus
