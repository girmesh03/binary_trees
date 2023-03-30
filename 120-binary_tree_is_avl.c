#include "binary_trees.h"

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
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
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

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lh, rh, balance_factor;

	if (!tree)
		return (1);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);
	balance_factor = lh - rh;

	if (balance_factor >= 1 && balance_factor <= -1)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	if (!binary_tree_is_avl(tree->left) ||
		!binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
