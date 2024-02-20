include comp/srcs.mk
include comp/vars.mk
include comp/color.mk

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "🔗 $(GREEN)> $(YELLOW)ar $(RED)-rcs $(GREEN)$(NAME)$(END) $(OBJS)"
	@echo "📚 $(CYAN)libft done\n$(END)"

$(BUILDDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	@mkdir -p $(DEPENDENCIESDIR)$(@:$(BUILDDIR)%$(@F)=%)
	@$(CC) $(CFLAGS) -I$(INCLUDEDIR) -MMD -MP -c $< -o $@
	@echo "🔧 $(GREEN)> $(YELLOW)$(CC) $(RED)$(CFLAGS) $(GRAY)-I$(INCLUDEDIR) $(RED)-MMD -MP $(END)-c $< -o $@ $(END)"
	@mv $(@:%.o=%.d) $(DEPENDENCIESDIR)$(@:$(BUILDDIR)%.o=%.d)

-include $(DEPS)

norminette:
	@echo "$(UNDERLINE)$(GREEN)norminette: $(shell pwd)$(END)"
	@mkdir -p $(BUILDDIR)
	@norminette $(INCLUDEDIR) $(SRCDIR) > $(BUILDDIR)norminette.log ; echo -n ""
	@while IFS= read -r line; do \
		if echo $$line | grep -q "Error!"; then \
			echo '$(UNDERLINE)''$(YELLOW)'$$line'$(END)'; \
		elif echo $$line | grep -q "OK!"; then \
			echo -n '$(END)''$(END)'; \
		else \
			echo '$(RED)'$$line'$(END)'; \
		fi; \
	done < $(BUILDDIR)norminette.log

clean:
	@rm -rf $(BUILDDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all --no-print-directory

.PHONY:	all	clean fclean re
