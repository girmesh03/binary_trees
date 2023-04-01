#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: pointer to the sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* if the the tree is empty or the node is the root, return NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* if the node is a right child of its parent, */
	/* then return the left child of its parent */
	if (node->parent->right == node)
		return (node->parent->left);
	/* otherwise, it's sibling is the right child of its parent */
	return (node->parent->right);
}
