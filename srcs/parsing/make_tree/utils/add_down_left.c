
#include "add_tree.h"

t_tree *down_left(t_tree *root, t_tree *branch, t_tree *new)
{
	if (branch->left == NULL)
		return (add_down(root, &branch->left, new));
	return (down_left(root, branch->left, new));
}
