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

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	/* if either of the nodes is NULL, return NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	/* get the depth of both the node pointers */
	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	/* if the depth of first node is greater than the depth of second node */
	/* then move the first node pointer up until both the pointers are at */
	/* the same depth */
	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}
	/* if the depth of second node is greater than the depth of first node */
	/* then move the second node pointer up until both the pointers are at */
	/* the same depth */
	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}

	/* now, both the pointers are at the same depth, so move both the */
	/* pointers up until both the pointers are pointing to the same node */
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	/* if both the pointers are NULL, then return NULL */
	return (NULL);
}
