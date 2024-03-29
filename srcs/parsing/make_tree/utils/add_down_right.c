
#include "add_tree.h"

t_tree	*down_right(t_tree *root, t_tree *branch, t_tree *new)
{
	t_tree	*tmp;

	if (new->type == CMD)
		return (add_down(root, &branch->right, new));
	tmp = root->right;
	root->right = new;
	new->left = tmp;
	return (root);
}
