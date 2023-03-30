#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: size of the tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree->left);
	size += binary_tree_size(tree->right) + 1;

	return (size);
}

/**
 * heap_to_sorted_array - Converts a Max Binary Heap
 * to a sorted array of integers
 * @heap: A pointer to the root node of the heap to convert
 * @size: A pointer to the size of the array
 * Return: A pointer to the sorted array, or NULL on failure
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array = NULL;
	size_t i = 0;

	if (heap == NULL || size == NULL)
		return (NULL);

	*size = binary_tree_size(heap);
	array = malloc(sizeof(int) * (*size));
	if (array == NULL)
		return (NULL);

	while (heap != NULL)
	{
		array[i] = heap_extract(&heap);
		i++;
	}

	return (array);
}
