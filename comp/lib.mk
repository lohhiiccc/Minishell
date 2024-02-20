LIBDIR = lib/
LIBPRINTF = $(LIBDIR)printf/
LIBFT = $(LIBDIR)libft/

LIBS = $(LIBFT)libft.a $(LIBPRINTF)libftprintf.a

$(LIBS): FORCE
	@$(MAKE) -C $(@D) --no-print-directory
