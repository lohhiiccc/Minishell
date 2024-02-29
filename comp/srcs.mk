SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/
PARSINGDIR = $(SRCDIR)parsing/
TOOLSDIR = $(SRCDIR)tools/
TREEDIR = $(TOOLSDIR)tree/
TOKENDIR = $(TOOLSDIR)token/

SRCPROMT = prompt

SRCLEXER = lexer \
		   lex_pipe \
		   lex_string \
		   lex_operator \
		   lex_parenthese \
		   lex_redirection \

SRCPARSING = parsing

SRCTREE =  ft_clean_tree \
		   ft_join_tree \
		   ft_new_tree

SRCTOKEN = free_token_lst \
		   quote \
		   get_next_token \
		   get_tokens

SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(TREEDIR), $(addsuffix .c, $(SRCTREE))) \
	   $(addprefix $(TOKENDIR), $(addsuffix .c, $(SRCTOKEN))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER)))
