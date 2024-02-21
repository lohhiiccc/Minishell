SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/

SRCPROMT = prompt

SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT)))
