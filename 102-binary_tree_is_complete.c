#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete_aux - Checks if a binary tree is complete recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @index: The index of the current node.
 * @size: The size of the binary tree.
 *
 * Return: 1 if the binary tree is complete, otherwise 0.
 */
int binary_tree_is_complete_aux(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (binary_tree_is_complete_aux(tree->left, 2 * index + 1, size) &&
			binary_tree_is_complete_aux(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the binary tree is complete, otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = 0;
	int index = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (binary_tree_is_complete_aux(tree, index, size));
}
