#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of the tree
 *
 * Note: height of a tree is height of root node, height of a node is the
 * the longest path from current node to leaf node.
 * and height of a leaf node is 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	/* height of an empty tree or a leaf node is 0 so return 0 */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	/* else, recursively calculate the height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* return the height of any node except leaf node and empty tree */
	/* 1 is added to the height of the node to account the current node */
	/* in which the height is being calculated */
	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}
