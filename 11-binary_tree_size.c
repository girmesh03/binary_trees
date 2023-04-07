#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the any node or 0 if tree is empty.
 *
 * Note: size of a tree is the number of nodes in the tree,
 * size of a node is the sum of number of nodes in left and right subtrees,
 * the current node, size of a leaf node is 1 and size of an empty tree is 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* size of an empty tree is 0 so return 0 */
	if (tree == NULL)
		return (0);

	/* else, recursively return the sum of number of nodes in left and right */
	/* subtrees and the current node */
	return (1 + (binary_tree_size(tree->left) +
				 binary_tree_size(tree->right)));
}
