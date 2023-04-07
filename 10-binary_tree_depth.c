#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 *
 * Note: depth of a node is the number of edges from the node to the root node
 * in other words, the number of ancestors of the node including the root node
 * OR the number of edges on the path from the root node to the node,
 * depth of root node is 0, depth of a leaf node is the height of the tree,
 * and depth of a tree is the height of the root node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* depth of an empty tree or root node is 0 so return 0 */
	if (tree == NULL || tree->parent == NULL)
		return (0);
	/* else, recursively calculate the depth of the parent node */
	return (1 + binary_tree_depth(tree->parent));
}
