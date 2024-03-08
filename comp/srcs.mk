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
PRINTTREEDIR = $(TREEDIR)print_tree/
MAKETREEDIR = $(PARSINGDIR)make_tree/

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

SRCEXEC = exec \
		  exec_and \
		  exec_or \
		  exec_apend \
		  exec_build_in \
		  exec_cmd \
		  exec_here_doc \
		  exec_input \
		  exec_output \
		  exec_pipe \
		  exec_utils \

SRCMAKE_NODE = command \
			   operator \
			   redirection

SRCPRINTTREE = print

SRCMAKE_TREE = make_tree \
			   is_type \
			   add_tree

SRCS =  $(SRCDIR)main.c\
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(TREEDIR), $(addsuffix .c, $(SRCTREE))) \
	   $(addprefix $(TOKENDIR), $(addsuffix .c, $(SRCTOKEN))) \
	   $(addprefix $(BUILD_INDIR), $(addsuffix .c, $(SRCBUILD_IN))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER))) \
	   $(addprefix $(LEXSYNTAXDIR), $(addsuffix .c, $(SRCLEXSYNTAX))) \
	   $(addprefix $(MAKE_NODEDIR), $(addsuffix .c, $(SRCMAKE_NODE))) \
	   $(addprefix $(PRINTTREEDIR), $(addsuffix .c, $(SRCPRINTTREE))) \
	   $(addprefix $(MAKETREEDIR), $(addsuffix .c, $(SRCMAKE_TREE))) \
	   $(addprefix $(EXECDIR), $(addsuffix .c, $(SRCEXEC)))
