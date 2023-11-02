#include "binary_trees.h"

/**
 * binary_tree_nodes - Calc the nodes at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the num of nodes.
 * Return: Return 0 for a NULL tree, or return the height otherwise.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
