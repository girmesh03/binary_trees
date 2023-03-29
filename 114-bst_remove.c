#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value
 * If tree is NULL or if nothing is found, return NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
		return (bst_search(tree->left, value));

	if (value > tree->n)
		return (bst_search(tree->right, value));

	return ((bst_t *)tree);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = NULL;

	if (root == NULL)
		return (NULL);

	node = bst_search(root, value);
	if (node == NULL)
		return (root);

	if (node->left == NULL && node->right == NULL)
	{
		if (node->parent == NULL)
		{
			free(node);
			return (NULL);
		}
		if (node->parent->left == node)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
		free(node);
		return (root);
	}

	if (node->left == NULL || node->right == NULL)
	{
		if (node->parent == NULL)
		{
			if (node->left != NULL)
				node->left->parent = NULL;
			else
				node->right->parent = NULL;
			free(node);
			return (root);
		}
		if (node->parent->left == node)
		{
			if (node->left != NULL)
			{
				node->parent->left = node->left;
				node->left->parent = node->parent;
			}
			else
			{
				node->parent->left = node->right;
				node->right->parent = node->parent;
			}
		}
		else
		{
			if (node->left != NULL)
			{
				node->parent->right = node->left;
				node->left->parent = node->parent;
			}
			else
			{
				node->parent->right = node->right;
				node->right->parent = node->parent;
			}
		}
		free(node);
		return (root);
	}

	node->n = node->right->n;
	bst_remove(node->right, node->n);
	return (root);
}
