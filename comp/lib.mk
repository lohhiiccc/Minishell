LIBDIR = lib/
LIBFT = $(LIBDIR)libft/
LIBPRINTF = $(LIBDIR)printf/

LIBS = $(LIBFT)libft.a  $(LIBPRINTF)libftprintf.a

$(LIBS): FORCE
	@$(MAKE) -C $(@D) --no-print-directory
