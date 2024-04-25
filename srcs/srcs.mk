#------------------------------------dir----------------------------------#

SRC_DIR = srcs/
PROMPT_DIR = $(SRC_DIR)prompt/
LEXER_DIR = $(SRC_DIR)lexer/
LEXSYNTAX_DIR = $(LEXER_DIR)syntax_checker/
PARSING_DIR = $(SRC_DIR)parsing/
TOOLS_DIR = $(SRC_DIR)tools/
TREE_DIR = $(TOOLS_DIR)tree/
TOKEN_DIR = $(TOOLS_DIR)token/
BUILD_IN_DIR = $(SRC_DIR)build-in/
EXEC_DIR = $(SRC_DIR)exec/
MAKE_NODE_DIR = $(TREE_DIR)make_node/
PRINTTREE_DIR = $(TREE_DIR)print_tree/
MAKETREE_DIR = $(PARSING_DIR)make_tree/
ENV_DIR = $(SRC_DIR)env/
EXPANDER_DIR = $(SRC_DIR)expander/
MAKETREE_UTILS_DIR = $(MAKETREE_DIR)utils/
EXPANDER_UTILS_DIR = $(EXPANDER_DIR)utils/
EXPANDER_EXPAND_DIR = $(EXPANDER_DIR)expand/
SIGNAL_DIR = $(SRC_DIR)signal/
WILDCARD_DIR = $(EXPANDER_DIR)wildcard/
TILDE_EXPAND_DIR = $(EXPANDER_DIR)tilde/
HEREDOC_DIR = $(SRC_DIR)here_doc/

#-------------------------------------------------------------------------#
#----------------------------------files-----------------------------------#

SRC_PROMT = prompt \
		    history \
		    prompt_skin \

SRC_LEXER = lexer \
		    launch_checker \
		    print_syntax_error \

SRC_LEXSYNTAX = lex_pipe \
			    lex_string \
			    lex_operator \
			    lex_parenthese \
		   	    lex_redirection \

SRC_PARSING = parsing \

SRC_TREE = ft_new_tree \
		   ft_join_tree \
		   ft_clean_tree \

SRC_TOKEN = quote \
		    tag_args \
		    tag_files \
		    get_tokens \
		    get_next_token \
		    free_token_lst \

SRC_BUILD_IN = cd \
			   env \
			   pwd \
			   echo \
			   exit \
			   unset \
			   export \

SRC_EXEC = exec \
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
		   exec_exe \

SRC_MAKE_NODE = command \
			    operator \
			    redirection \

SRC_PRINT_TREE = print \

SRC_MAKE_TREE = is_type \
			    make_tree \
			    add_subtree \

SRC_MAKETREE_UTILS = add_down \
					add_up_right \
					add_down_left \
					add_down_right \
					add_redirection \

SRC_ENV = init_env \
		  clear_env \
		  found_value_of_variable \

SRC_EXPANDER = expand_cmd \
		   	   expand_file \
			   expand_wildcard \
		  	   expand_here_doc_delimiter \

SRC_EXPANDER_UTILS = add_var \
				    expand_str \
				    var_charset \
				    free_expand \
				    get_env_line \
				    set_negative \
				    have_wildecard \

SRC_EXPANDER_EXPAND = expand_var \
			  	      expand_ret \
			  	      expand_quote \

SRC_SIGNAL = signal_main \
			 signal_main_wait \
			 signal_child \
			 do_nothing \

SRC_WILDCARD = is_match \
			   wildcard \
			   get_folder \
			   expand_one_wildcard \

SRC_TILDE_EXPAND = tilde

SRC_HERE_DOC = pars_heredoc \
			   here_doc_prompt \
			   create_here_doc_file \

#--------------------------------------------------------------------------#
#----------------------------------srcs------------------------------------#

SRCS = $(SRC_DIR)main.c \
	   $(addprefix $(ENV_DIR), $(addsuffix .c, $(SRC_ENV))) \
	   $(addprefix $(TREE_DIR), $(addsuffix .c, $(SRC_TREE))) \
	   $(addprefix $(EXEC_DIR), $(addsuffix .c, $(SRC_EXEC))) \
	   $(addprefix $(TOKEN_DIR), $(addsuffix .c, $(SRC_TOKEN))) \
	   $(addprefix $(LEXER_DIR), $(addsuffix .c, $(SRC_LEXER))) \
	   $(addprefix $(PROMPT_DIR), $(addsuffix .c, $(SRC_PROMT))) \
	   $(addprefix $(SIGNAL_DIR), $(addsuffix .c, $(SRC_SIGNAL))) \
	   $(addprefix $(PARSING_DIR), $(addsuffix .c, $(SRC_PARSING))) \
	   $(addprefix $(HEREDOC_DIR), $(addsuffix .c, $(SRC_HERE_DOC))) \
	   $(addprefix $(WILDCARD_DIR), $(addsuffix .c, $(SRC_WILDCARD))) \
	   $(addprefix $(EXPANDER_DIR), $(addsuffix .c, $(SRC_EXPANDER))) \
	   $(addprefix $(BUILD_IN_DIR), $(addsuffix .c, $(SRC_BUILD_IN))) \
	   $(addprefix $(MAKETREE_DIR), $(addsuffix .c, $(SRC_MAKE_TREE))) \
	   $(addprefix $(LEXSYNTAX_DIR), $(addsuffix .c, $(SRC_LEXSYNTAX))) \
	   $(addprefix $(MAKE_NODE_DIR), $(addsuffix .c, $(SRC_MAKE_NODE))) \
	   $(addprefix $(PRINTTREE_DIR), $(addsuffix .c, $(SRC_PRINT_TREE))) \
	   $(addprefix $(TILDE_EXPAND_DIR), $(addsuffix .c, $(SRC_TILDE_EXPAND))) \
	   $(addprefix $(MAKETREE_UTILS_DIR), $(addsuffix .c, $(SRC_MAKETREE_UTILS))) \
	   $(addprefix $(EXPANDER_UTILS_DIR), $(addsuffix .c, $(SRC_EXPANDER_UTILS))) \
	   $(addprefix $(EXPANDER_EXPAND_DIR), $(addsuffix .c, $(SRC_EXPANDER_EXPAND))) \

#--------------------------------------------------------------------------#
