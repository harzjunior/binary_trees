#include "binary_trees.h"

/**
 * bst_search - Finds a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to perform the search.
 * @value: The value to look for within the BST.
 *
 * Return: NULL for NULL tree or value not found, otherwise, a node pointer.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
