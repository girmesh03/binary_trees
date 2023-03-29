#include "binary_trees.h"
#include <limits.h>

/**
 * check_bst - helper function to recursively
 * check if a tree is a valid BST
 * @node: pointer to the current node being checked
 * @min: minimum value the node can have
 * @max: maximum value the node can have
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int check_bst(const binary_tree_t *node, int min, int max)
{
	if (node == NULL)
		return (1);

	if (node->n < min || node->n > max)
		return (0);

	return (check_bst(node->left, min, node->n - 1) &&
			check_bst(node->right, node->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree
 * is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}
