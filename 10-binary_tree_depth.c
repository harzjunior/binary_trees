#include "binary_trees.h"

/**
 * binary_tree_depth - Calculates the depth of a node in a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: Return 0 for a NULL tree, or return the height otherwise.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
