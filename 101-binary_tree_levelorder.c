#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: height of the tree
 *
 * Note: height of a tree is height of root node, height of a node is the
 * the longest path from current node to leaf node.
 * and height of a leaf node is 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	/* height of an empty tree or a leaf node is 0 so return 0 */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	/* else, recursively calculate the height of left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* return the height of any node except leaf node and empty tree */
	/* 1 is added to the height of the node to account the current node */
	/* in which the height is being calculated */
	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_to_array - converts a binary tree to an array
 * @root: pointer to the root node of the tree to convert
 * @arr: pointer to the array to store the values
 * @index: index of the array where the value of the node is to be stored
 * Return: void
 */
void binary_tree_to_array(const binary_tree_t *root, int *arr, int index)
{
	/* if root is NULL, return */
	if (root == NULL)
		return;

	/* store the value of the node in the array */
	arr[index] = root->n;

	/* recursively call the function for left and right child */
	binary_tree_to_array(root->left, arr, 2 * index + 1);
	binary_tree_to_array(root->right, arr, 2 * index + 2);
}

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int *arr, height, max_nodes, i;

	/* if tree or func is NULL, return */
	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	/* formula to calculate maximum number */
	/* of nodes in a binary tree of height h */
	max_nodes = (1 << (height + 1)) - 1;

	/* allocate memory for the array */
	arr = malloc(max_nodes * sizeof(int));
	if (arr == NULL)
		return;

	/* initialize the array with -1 */
	for (i = 0; i < max_nodes; i++)
		arr[i] = -1;

	/* convert the binary tree to an array */
	binary_tree_to_array(tree, arr, 0);

	/* call the function for each node in the array */
	for (i = 0; i < max_nodes; i++)
	{
		if (arr[i] != -1)
			func(arr[i]);
	}
	/* free the allocated memory */
	free(arr);
}
