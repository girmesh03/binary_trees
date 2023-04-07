#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node,
 * or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* if parent is empty, impossible to insert so return NULL */
	if (parent == NULL)
		return (NULL);

	/* create new node and if creation fails, return NULL */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	/* if parent has no left child, simply insert new node as left child */
	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	/* if parent has a left child, insert new node as left child */
	/* and move the current left child to the left of the new node */
	else if (parent->left != NULL)
	{
		/* the new node's left child is the current left child */
		new_node->left = parent->left;
		/* the current left child's parent is the new node */
		parent->left->parent = new_node;
		/* the parent's left child is the new node */
		parent->left = new_node;
	}
	/* return the pointer to the inserted node */
	return (new_node);
}
