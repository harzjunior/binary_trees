#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the leftmost child of another node.
 *
 * @parent: Pointer to the node where the left child is to be inserted.
 * @value: The value to be placed in the new node.
 * Return: Pointer to the newly created node. Returns NULL in case of failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
