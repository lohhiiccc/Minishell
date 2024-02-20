LIBDIR = lib/
LIBFT = $(LIBDIR)libft/

LIBS = $(LIBFT)libft.a

$(LIBS): FORCE
	@$(MAKE) -C $(@D) --no-print-directory
