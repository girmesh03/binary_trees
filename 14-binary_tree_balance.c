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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	/* height of an empty tree is 0 so return 0 or */
	/* height of a leaf node is 0, balance factor 0 so return 0 */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	/* else, recursively sum the height of left and right subtrees */
	/* if left or right child exists */
	if (tree->left != NULL)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_height = 1 + binary_tree_height(tree->right);

	/* return the balance factor of any node */
	/* balance factor of a node is the difference between height of left */
	/* and right subtrees */
	return (left_height - right_height);
}
