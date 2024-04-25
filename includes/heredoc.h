
#ifndef HEREDOC_H
# define HEREDOC_H
# include "tree.h"
# define HERE_DOC_EOF "Minichell: warning: here-document delimited by end-of-file (wanted `%s')\n"

int	create_file_here_doc(t_tree *tree, t_env *env);
int	read_here_doc(t_tree *tree);

#endif