#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes the entire binary tree
 * or if tree is NULL, does nothing
 * @tree: Pointer to the root node of the tree to delete
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	/* Base case: If tree is empty, return */
	if (tree == NULL)
		return;
	/* Delete the left and right subtrees */
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	/* Delete the root node or parent node */
	free(tree);
}
