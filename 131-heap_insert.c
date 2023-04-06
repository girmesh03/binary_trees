#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 * Return: size of the tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + (binary_tree_size(tree->left) +
				 binary_tree_size(tree->right)));
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *current;
	size_t size = 0;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	current = *root;
	while (current)
	{
		size = binary_tree_size(current->left);
		if (size == binary_tree_size(current->right))
		{
			if (!current->left)
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				break;
			}
			current = current->left;
		}
		else
		{
			if (!current->right)
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				break;
			}
			current = current->right;
		}
	}
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}
