SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/
PARSINGDIR = $(SRCDIR)parsing/
TOOLSDIR = $(SRCDIR)tools/
TREEDIR = $(TOOLSDIR)tree/


SRCPROMT = prompt
SRCLEXER = lexer \
		   operator \
		   parenthese \
		   quote \
		   get_type \
		   redirection
SRCPARSING = parsing
SRCTREE =  ft_clean_tree \
		   ft_join_tree \
		   ft_new_tree


SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(TREEDIR), $(addsuffix .c, $(SRCTREE))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER)))
