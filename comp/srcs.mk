SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/
PARSINGDIR = $(SRCDIR)parsing/


SRCPROMT = prompt
SRCLEXER = lexer \
		   operator \
		   parenthese \
		   quote \
		   get_type \
		   redirection
SRCPARSING = parsing

SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER)))
