#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = 1 + binary_tree_height(tree->left);
	right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * print_level - prints nodes at a given level
 * @tree: pointer to the root node of the tree to traverse
 * @level: level to print
 * @func: pointer to a function to call for each node
 * Return: nothing
 */

void print_level(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 0)
		func(tree->n);
	else if (level > 0)
	{
		print_level(tree->left, func, level - 1);
		print_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - goes via a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0, level;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	level;

	for (level = 0; level <= height; level++)
		print_level(tree, func, level);
}
