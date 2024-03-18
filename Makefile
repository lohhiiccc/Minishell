include comp/srcs.mk
include comp/vars.mk
include comp/color.mk
include comp/lib.mk
-include $(DEPS)

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(CFLAGS) -I$(LIBFT)includes/ -Iincludes/ $(OBJS) -L$(LIBFT) -lft -lreadline -o $(NAME)
	@echo "🔗 $(GREEN)> $(YELLOW)$(CC) $(RED)$(CFLAGS) $(GRAY) -I$(LIBFT)includes/ -Iincludes/$(END) $(OBJS)$(GRAY) -L$(LIBFT) -L$(LIBPRINTF)$(YELLOW) -lft -lreadline $(END) -o $(GREEN)$(NAME)$(END)"
	@echo "📚 $(CYAN)$(NAME) done\n$(END)"

$(BUILDDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	@mkdir -p $(DEPENDENCIESDIR)$(@:$(BUILDDIR)%$(@F)=%)
	@$(CC) $(CFLAGS) -I$(LIBFT)includes/ -I$(INCLUDEDIR) -MMD -MP -c $< -o $@
	@echo "🔧 $(GREEN)> $(YELLOW)$(CC) $(RED)$(CFLAGS) $(GRAY) -I$(LIBFT)includes/ -I$(INCLUDEDIR) $(RED)-MMD -MP $(END)-c $< -o $@ $(END)"
	@mv $(@:%.o=%.d) $(DEPENDENCIESDIR)$(@:$(BUILDDIR)%.o=%.d)

clean:
	@echo "$(UNDERLINE)$(GREEN)$(NAME)$(END) => $(YELLOW)clean$(END)"
	@rm -rf $(BUILDDIR)
	@$(MAKE) -C $(LIBFT) $@

fclean: clean
	@echo "$(UNDERLINE)$(GREEN)$(NAME)$(END) => $(RED)fclean$(END)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) $@

re: fclean
	@$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
.DEFAULT_GOAL := all
