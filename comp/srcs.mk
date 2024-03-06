SRCDIR = srcs/
PROMPTDIR = $(SRCDIR)prompt/
LEXERDIR = $(SRCDIR)lexer/
LEXSYNTAXDIR = $(LEXERDIR)syntax_checker/
PARSINGDIR = $(SRCDIR)parsing/
TOOLSDIR = $(SRCDIR)tools/
TREEDIR = $(TOOLSDIR)tree/
TOKENDIR = $(TOOLSDIR)token/
BUILD_INDIR= $(SRCDIR)build-in/
EXECDIR= $(SRCDIR)exec/
MAKE_NODEDIR = $(TREEDIR)make_node/

SRCPROMT = prompt

SRCLEXER = lexer \
		   launch_checker

SRCLEXSYNTAX = lex_pipe \
			   lex_string \
			   lex_operator \
			   lex_parenthese \
		   	   lex_redirection

SRCPARSING = parsing \
			 pars_parenthese

SRCTREE =  ft_clean_tree \
		   ft_join_tree \
		   ft_new_tree

SRCTOKEN = quote \
		   tag_args \
		   tag_files \
		   get_tokens \
		   get_next_token \
		   free_token_lst \

SRCBUILD_IN = cd \
			  env \
			  pwd \
			  exit \
			  echo \
			  unset \
			  export \

SRCEXEC = exec

SRCMAKE_NODE = command \
			   redirection

SRCS =  $(SRCDIR)main.c\
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(TREEDIR), $(addsuffix .c, $(SRCTREE))) \
	   $(addprefix $(TOKENDIR), $(addsuffix .c, $(SRCTOKEN))) \
	   $(addprefix $(BUILD_INDIR), $(addsuffix .c, $(SRCBUILD_IN))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER))) \
	   $(addprefix $(LEXSYNTAXDIR), $(addsuffix .c, $(SRCLEXSYNTAX))) \
	   $(addprefix $(MAKE_NODEDIR), $(addsuffix .c, $(SRCMAKE_NODE))) \
	   $(addprefix $(EXECDIR), $(addsuffix .c, $(SRCEXEC)))
