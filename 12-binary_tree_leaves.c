#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	/* If tree is empty, return 0 */
	if (tree == NULL)
		return (0);
	/* If tree is a leaf, increment leaf node count by 1 */
	/* and recursively check the remaining left and right subtrees */
	if (tree->left == NULL && tree->right == NULL)
		return (1 + (binary_tree_leaves(tree->left) +
					 binary_tree_leaves(tree->right)));
	/* otherwise, recursively check the left and right subtrees */
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
