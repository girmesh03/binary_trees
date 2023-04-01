#include "binary_trees.h"

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
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is full, otherwise 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) &&
				binary_tree_is_full(tree->right));
	return (0);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	/* take account of leaf nodes */
	if (!tree->left && !tree->right)
		return (1);

	/* take account of nodes with only one child */
	if (tree->left && !tree->right)
		return (0);

	/* take account of nodes with two children */
	if (tree->left && tree->right)
	{
		left_height = binary_tree_height(tree->left);
		right_height = binary_tree_height(tree->right);

		if (left_height == right_height)
		{
			if (binary_tree_is_full(tree->left) &&
				binary_tree_is_complete(tree->right))
				return (1);
		}
		else if (left_height == right_height + 1)
		{
			if (binary_tree_is_complete(tree->left) &&
				binary_tree_is_full(tree->right))
				return (1);
		}
	}
	return (0);
}
