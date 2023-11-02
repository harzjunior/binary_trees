#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Determines the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: Returns the common ancestor or NULL when none exists.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;
	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - Determines the depth of a node within a binary tree.
 * @tree: A pointer to the node for which to determine the depth.
 *
 * Return: Returns 0 for a NULL tree, or returns the depth otherwise.
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
