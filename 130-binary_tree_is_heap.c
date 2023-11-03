#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - Traverses a tree, checking each node as the max value.
 * @tree: A pointer to the root of the tree.
 * Return: 1 if all nodes are max, else 0.
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_max(tree->right);
	}
	return (tmp1 && tmp2);
}
/**
 * binary_tree_is_heap - Verifies if a binary tree is a heap.
 * @tree: A pointer to the node.
 * Return: Returns 1 if it's a Binary Search Tree (BST), otherwise 0.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (check_max(tree));
}
