#include "binary_trees.h"

/**
 * binary_tree_sibling - Locates the sibling of a node in a binary tree.
 * @node: A pointer to the node for which the sibling is to be found.
 *
 * Return: Returns the sibling's pointer if available; otherwise, returns NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
