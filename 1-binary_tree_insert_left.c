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
	binary_tree_t *pleft = NULL, *new_node = NULL;

	if (!parent)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	pleft = parent->left;
	parent->left = new_node;

	if (pleft)
	{
		pleft->parent = new_node;
		new_node->left = pleft;
	}

	return (new_node);
}
