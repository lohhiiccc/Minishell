NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -g3
BUILDDIR = build/
INCLUDEDIR = includes/
DEPENDENCIESDIR = $(BUILDDIR)/dependencies/

OBJS = $(SRCS:$(SRCDIR)%.c=$(BUILDDIR)%.o)
DEPS = $(SRCS:$(SRCDIR)%.c=$(DEPENDENCIESDIR)%.d)