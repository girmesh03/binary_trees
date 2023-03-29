#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes the entire binary tree
 * or if tree is NULL, does nothing
 * @tree: Pointer to the root node of the tree to delete
 * Return: void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	/* Recursively delete the left and right subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/* Once the subtrees are deleted, delete the current node */
	if (tree->parent != NULL)
	{
		/* Update the parent's left or right pointer, if necessary */
		if (tree->parent->left == tree)
			tree->parent->left = NULL;
		else
			tree->parent->right = NULL;
	}

	free(tree);
}
