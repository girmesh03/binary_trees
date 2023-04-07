#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, otherwise 0
 *
 * A full binary tree is a binary tree in which every node has either 0 or 2
 * children. i.e either a leaf node or a node with two children.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/* empty tree is not full */
	if (tree == NULL)
		return (0);

	/* if tree is a leaf node or has two children, return 1 */
	if ((tree->left == NULL && tree->right == NULL) ||
		(binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right)))
		return (1);

	/* otherwise, return 0 */
	return (0);
}
