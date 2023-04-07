#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* if parent is empty, impossible to insert so return NULL */
	if (parent == NULL)
		return (NULL);
	/* create new node and if creation fails, return NULL */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	/* if parent has no right child, simply insert new node as right child */
	if (parent->right == NULL)
	{
		parent->right = new_node;
	}
	/* if parent has a right child, insert new node as right child */
	/* and move the current right child to the right of the new node */
	else if (parent->right != NULL)
	{
		/* the new_node right pointer points to the current right child */
		new_node->right = parent->right;
		/* the current right child's parent is the new node */
		parent->right->parent = new_node;
		/* the parent right pointer points to the new node */
		parent->right = new_node;
	}
	/* return the pointer to the inserted node */
	return (new_node);
}
