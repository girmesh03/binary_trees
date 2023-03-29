#include "binary_trees.h"

/**
 * binary_tree_is_complete_aux - auxiliary function to
 * check if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * @index: index of the current node
 * @size: size of the binary tree
 * Return: 1 if complete, 0 otherwise
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
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size of
 *
 * Return: size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not or if tree is NULL
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
