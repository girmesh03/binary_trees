#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *right_ancestor, *left_ancestor;

	if (!first || !second)
		return (NULL);

	if (first == second || first == second->parent)
		return ((binary_tree_t *)first);
	if (second == first->parent)
		return ((binary_tree_t *)second);

	right_ancestor = binary_trees_ancestor(first, second->parent);
	left_ancestor = binary_trees_ancestor(first->parent, second);

	if (right_ancestor)
		return (right_ancestor);
	else if (left_ancestor)
		return (left_ancestor);
	else
		return (NULL);
}
