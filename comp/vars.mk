NAME = minishell

MAKEFLAGS += --no-print-directory

CFLAGS = -Wall -Wextra -Werror -g3
BUILDDIRBACKUP = build/
BUILDDIR = $(BUILDDIRBACKUP)
INCLUDEDIR = includes/
DEPENDENCIESDIR = $(BUILDDIR)dependencies/

OBJS = $(SRCS:$(SRCDIR)%.c=$(BUILDDIR)%.o)
DEPS = $(SRCS:$(SRCDIR)%.c=$(DEPENDENCIESDIR)%.d)