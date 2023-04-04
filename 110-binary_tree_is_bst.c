#include "binary_trees.h"

/**
 * is_bst - recursively checks if a binary tree is a valid BST
 * @node: pointer to the current node being checked
 * @min: minimum value the node can have
 * @max: maximum value the node can have
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */

int is_bst(const binary_tree_t *node, int min, int max)
{
	/* if the node is a leaf node, return 1 */
	/* b/c a leaf node is a valid BST */
	if (node == NULL)
		return (1);

	/* if the following conditions are met, the tree is a valid BST */
	/* 1. check the node value is in b/n min and max range */
	/* 2. check the left subtree and right subtree is a valid BST */
	if ((node->n > min && node->n < max) &&
		(is_bst(node->left, min, node->n)) &&
		(is_bst(node->right, node->n, max)))
	{
		return (1);
	}
	else
	{
		/*otherwise, the tree is not a valid BST */
		return (0);
	}
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

	return (is_bst(tree, INT_MIN, INT_MAX));
}
