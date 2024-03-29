
#include "add_tree.h"

t_tree	*add_up_right(t_tree *root, t_tree *new)
{
	new->left = root;
	return (new);
}
