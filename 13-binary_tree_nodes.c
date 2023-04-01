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
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* if the current node is not a leaf, then it has at least one child */
	/* so add 1 to the number of nodes and */
	/* call recursively on the left and right */
	/* then return the number of nodes */
	if (!(binary_tree_is_leaf(tree)))
		return (1 + (binary_tree_nodes(tree->left) +
					 binary_tree_nodes(tree->right)));

	/* otherwise, the current node is a leaf, which has no children */
	return (0);
}
