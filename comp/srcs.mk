SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/


SRCPROMT = prompt
SRCLEXER = lexer \
		   operator \
		   parenthese \
		   quote \
		   get_type

SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER)))
