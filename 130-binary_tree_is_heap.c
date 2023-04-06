#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + (binary_tree_size(tree->left) +
				 binary_tree_size(tree->right)));
}

/**
 * is_complete - Recursive function to check if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 * @size: The size of the tree.
 * @index: The current index of the node.
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int is_complete(const binary_tree_t *tree, size_t size, size_t index)
{
	if (tree == NULL)
		return (1);

	/* Check if the current node is within the size of the tree */
	if (index >= size)
		return (0);

	/* Recursively check the left and right subtrees */
	return (is_complete(tree->left, size, 2 * index + 1) &&
			is_complete(tree->right, size, 2 * index + 2));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	/* Compute the size of the tree */
	size = binary_tree_size(tree);

	/* Check if the tree is complete */
	return (is_complete(tree, size, 0));
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->right == NULL && tree->left != NULL)
	{
		if (tree->n >= tree->left->n)
			return (binary_tree_is_heap(tree->left));
		else
			return (0);
	}

	if (binary_tree_is_complete(tree) &&
		tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (binary_tree_is_heap(tree->left) &&
				binary_tree_is_heap(tree->right));
	else
		return (0);
}
