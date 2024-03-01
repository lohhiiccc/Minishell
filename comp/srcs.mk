SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/
PARSINGDIR = $(SRCDIR)parsing/
TOOLSDIR = $(SRCDIR)tools/
TREEDIR = $(TOOLSDIR)tree/
TOKENDIR = $(TOOLSDIR)token/
BUILD_INDIR= $(SRCDIR)build-in/
EXECDIR= $(SRCDIR)exec/

SRCPROMT = prompt

SRCLEXER = lexer \
		   lex_pipe \
		   lex_quote \
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

SRCBUILD_IN = cd \
			  env \
			  pwd \
			  exit \
			  echo \
			  unset \
			  export_\

SRCEXEC = exec

SRCS =  $(SRCDIR)main.c \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(TREEDIR), $(addsuffix .c, $(SRCTREE))) \
	   $(addprefix $(TOKENDIR), $(addsuffix .c, $(SRCTOKEN))) \
	   $(addprefix $(BUILD_INDIR), $(addsuffix .c, $(SRCBUILD_IN))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER))) \
	   $(addprefix $(EXECDIR), $(addsuffix .c, $(SRCEXEC)))
