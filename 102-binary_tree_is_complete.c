#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	return (node->left == NULL && node->right == NULL);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: height of the tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (MAX(left_height, right_height) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not or if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		if (binary_tree_is_leaf(tree->left) &&
			binary_tree_is_leaf(tree->right))
			return (1);

		if (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
			return (1);
	}

	return (0);
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (binary_tree_height(tree->left) == binary_tree_height(tree->right))
	{
		if (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right))
			return (1);
	}
	else if (binary_tree_height(tree->left) ==
			 binary_tree_height(tree->right) + 1)
	{
		if (binary_tree_is_complete(tree->left) &&
			binary_tree_is_perfect(tree->right))
			return (1);
	}

	return (0);
}
