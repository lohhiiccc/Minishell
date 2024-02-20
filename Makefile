include comp/srcs.mk
include comp/vars.mk
include comp/color.mk
include comp/lib.mk

all: $(NAME)

$(NAME): $(LIBS) $(OBJS) $(TRACE)
	@$(CC) $(CFLAGS) -I$(LIBFT)includes/ -I$(LIBPRINTF)header/ -Iincludes/ $(OBJS) -L$(LIBFT) -L$(LIBPRINTF) -lft -lftprintf -o $(NAME)
	@echo "🔗 $(GREEN)> $(YELLOW)$(CC) $(RED)$(CFLAGS) $(GRAY)-I$(LIBFT)includes/ -I$(LIBPRINTF)header/ -Iincludes/$(END) $(OBJS)$(GRAY) -L$(LIBFT) -L$(LIBPRINTF)$(YELLOW) -lft -lftprintf$(END) -o $(GREEN)$(NAME)$(END)"
	@echo "📚 $(CYAN)$(NAME) done\n$(END)"

$(BUILDDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	@mkdir -p $(DEPENDENCIESDIR)$(@:$(BUILDDIR)%$(@F)=%)
	@$(CC) $(CFLAGS) -I$(LIBFT)includes/ -I$(LIBPRINTF)header/ -I$(INCLUDEDIR) -MMD -MP -c $< -o $@
	@echo "🔧 $(GREEN)> $(YELLOW)$(CC) $(RED)$(CFLAGS) $(GRAY)-I$(LIBFT)includes/ -I$(LIBPRINTF)header/ -I$(INCLUDEDIR) $(RED)-MMD -MP $(END)-c $< -o $@ $(END)"
	@mv $(@:%.o=%.d) $(DEPENDENCIESDIR)$(@:$(BUILDDIR)%.o=%.d)

-include $(DEPS)

norminette:
	@$(MAKE) $@ -C $(LIBFT)
	@echo "$(UNDERLINE)$(GREEN)norminette: $(shell pwd)$(END)"
	@mkdir -p $(BUILDDIR)
	@norminette $(INCLUDEDIR) $(SRCDIR) > $(BUILDDIR)norminette.log ; echo -n
	@while IFS= read -r line; do \
		if echo $$line | grep -q "Error!"; then \
			echo '$(UNDERLINE)''$(YELLOW)'$$line'$(END)'; \
		elif echo $$line | grep -q "OK!"; then \
			echo -n '$(WHITE)''$(END)'; \
		else \
			echo '$(RED)'$$line'$(END)'; \
		fi; \
	done < $(BUILDDIR)norminette.log

clean:
	@echo "$(UNDERLINE)$(GREEN)$(NAME)$(END) => $(YELLOW)clean$(END)"
	@rm -rf $(BUILDDIR)
	@$(MAKE) -C $(LIBPRINTF) $@
	@$(MAKE) -C $(LIBFT) $@

fclean: clean
	@echo "$(UNDERLINE)$(GREEN)$(NAME)$(END) => $(RED)fclean$(END)"
	@rm -f $(NAME)
	@rm -f infile out
	@$(MAKE) -C $(LIBFT) $@
	@$(MAKE) -C $(LIBPRINTF) $@

re: fclean
	@$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE norminette
