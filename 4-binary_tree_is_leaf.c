#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* empty node can't be a leaf node so return 0 */
	if (node == NULL)
		return (0);
	/* otherwise, if node exists but has no children, return 1 */
	/* because it is a leaf node */
	return (node->left == NULL && node->right == NULL);
}
