SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/


SRCPROMT = prompt
SRCLEXER = lexer \
		   operator \
		   parenthese \
		   quote

SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER)))
