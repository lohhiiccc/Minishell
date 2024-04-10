#------------------------------------dir----------------------------------#

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
ENVDIR = $(SRCDIR)env/
EXPANDERDIR = $(SRCDIR)expander/
MAKETREEUTILSDIR= $(MAKETREEDIR)utils/
EXPANDERUTILSDIR = $(EXPANDERDIR)utils/
SIGNALDIR = $(SRCDIR)signal/

#-------------------------------------------------------------------------#
#----------------------------------files-----------------------------------#

SRCPROMT = prompt \
		   history \
		   prompt_skin \

SRCLEXER = lexer \
		   launch_checker \
		   print_syntax_error \

SRCLEXSYNTAX = lex_pipe \
			   lex_string \
			   lex_operator \
			   lex_parenthese \
		   	   lex_redirection \

SRCPARSING = parsing \

SRCTREE =  ft_new_tree \
		   ft_join_tree \
		   ft_clean_tree \

SRCTOKEN = quote \
		   tag_args \
		   tag_files \
		   get_tokens \
		   get_next_token \
		   free_token_lst \

SRCBUILD_IN = cd \
			  env \
			  pwd \
			  echo \
			  exit \
			  unset \
			  export \

SRCEXEC = exec \
		  exec_or \
		  exec_cmd \
		  exec_and \
		  find_path \
		  exec_pipe \
		  exec_utils \
		  clean_exit \
		  exec_apend \
		  exec_input \
		  exec_output \
		  exec_here_doc \
		  exec_build_in \

SRCMAKE_NODE = command \
			   operator \
			   redirection \

SRCPRINTTREE = print \

SRCMAKE_TREE = is_type \
			   make_tree \
			   add_subtree \

SRCMAKETREEUTILS = add_down \
				   add_up_right \
				   add_down_left \
				   add_down_right \
				   add_redirection \

SRCENV = init_env \
		 clear_env \

SRCEXPANDER = expander \
			  expand_var \
			  expand_ret \
			  expand_quote \
			  remove_quote \

SRCEXPANDERUTILS = var_charset \
			  	   quote_status \
				   get_env_line \

SRCSIGNAL = signal \


#--------------------------------------------------------------------------#
#----------------------------------srcs------------------------------------#

SRCS = $(SRCDIR)main.c \
	   $(addprefix $(ENVDIR), $(addsuffix .c, $(SRCENV))) \
	   $(addprefix $(TREEDIR), $(addsuffix .c, $(SRCTREE))) \
	   $(addprefix $(EXECDIR), $(addsuffix .c, $(SRCEXEC))) \
	   $(addprefix $(TOKENDIR), $(addsuffix .c, $(SRCTOKEN))) \
	   $(addprefix $(LEXERDIR), $(addsuffix .c, $(SRCLEXER))) \
	   $(addprefix $(PROMPTDIR), $(addsuffix .c, $(SRCPROMT))) \
	   $(addprefix $(SIGNALDIR), $(addsuffix .c, $(SRCSIGNAL))) \
	   $(addprefix $(PARSINGDIR), $(addsuffix .c, $(SRCPARSING))) \
	   $(addprefix $(EXPANDERDIR), $(addsuffix .c, $(SRCEXPANDER))) \
	   $(addprefix $(BUILD_INDIR), $(addsuffix .c, $(SRCBUILD_IN))) \
	   $(addprefix $(MAKETREEDIR), $(addsuffix .c, $(SRCMAKE_TREE))) \
	   $(addprefix $(LEXSYNTAXDIR), $(addsuffix .c, $(SRCLEXSYNTAX))) \
	   $(addprefix $(MAKE_NODEDIR), $(addsuffix .c, $(SRCMAKE_NODE))) \
	   $(addprefix $(PRINTTREEDIR), $(addsuffix .c, $(SRCPRINTTREE))) \
	   $(addprefix $(MAKETREEUTILSDIR), $(addsuffix .c, $(SRCMAKETREEUTILS))) \
	   $(addprefix $(EXPANDERUTILSDIR), $(addsuffix .c, $(SRCEXPANDERUTILS))) \

#--------------------------------------------------------------------------#
