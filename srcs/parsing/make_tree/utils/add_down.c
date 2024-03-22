
#include "add_tree.h"

t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_in_subtree(*branch, leaf);
	return (root);
}
