#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* if tree is empty, return NULL */
	if (tree == NULL)
		return (NULL);

	/* new root is the right child of the current root */
	/* if the right child is NULL, return the current root */
	/* b/c it's impossible to rotate one node */
	new_root = tree->right;
	if (new_root == NULL)
		return (tree);

	if (new_root->left == NULL)
	{
		/* if the new root has no left child, */
		/* the current root becomes the left child of the new root */
		new_root->left = tree;
		/* the current root's parent is the new root */
		tree->parent = new_root;
		/* the current root's right child is NULL */
		tree->right = NULL;
		/* the new root's parent is NULL */
		new_root->parent = NULL;
	}
	else if (new_root->left != NULL)
	{
		/* if the new root has a left child, */
		/* the current root becomes the left child of the new root */
		new_root->left->parent = tree;
		tree->right = new_root->left;
		new_root->left = tree;
		tree->parent = new_root;
		new_root->parent = NULL;
	}
	/* return the pointer to the new root */
	return (new_root);
}
