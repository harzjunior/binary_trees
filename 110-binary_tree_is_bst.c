#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Verifies whether a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree for the validation check.
 * @lo: The value of the smallest node encountered during the check.
 * @hi: The value of the largest node encountered during the check.
 *
 * Return: Returns 1 if the tree is a valid BST, otherwise 0.
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Verifies whether a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree for the validation check.
 *
 * Return: Returns 1 if the tree is a valid BST, and 0 if it is not.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
