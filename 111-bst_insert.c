#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;
	/* if tree is not a valid pointer, return NULL */
	if (!tree)
		return (NULL);
	/* if tree is empty, create a new node and return it */
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	/* no duplicates allowed, return NULL */
	if (value == (*tree)->n)
		return (NULL);
	/* if value is less than the current node, go left */
	if (value < (*tree)->n)
	{
		/* if there is a left child, go to the next left child node */
		if ((*tree)->left)
			return (bst_insert(&(*tree)->left, value));
		/* if there is no left child, create a new node and link it */
		new_node = binary_tree_node(*tree, value);
		(*tree)->left = new_node;
	}
	/* if value is greater than the current node, go right */
	else if (value > (*tree)->n)
	{
		/* if there is a right child, go to the next right child node */
		if ((*tree)->right)
			return (bst_insert(&(*tree)->right, value));
		/* if there is no right child, create a new node and link it */
		new_node = binary_tree_node(*tree, value);
		(*tree)->right = new_node;
	}
	return (new_node);
}
