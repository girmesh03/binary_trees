#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* If tree is empty, or a leaf node then return 0 */
	/* b/c we are only counting nodes with 1 or 2 children */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	/* otherwise, recursively return the sum of number of nodes in left and */
	/* right subtrees and the current node */
	return (1 + (binary_tree_nodes(tree->left) +
				 binary_tree_nodes(tree->right)));
}
