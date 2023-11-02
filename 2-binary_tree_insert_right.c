#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the rightmost child of another node.
 * @parent: Pointer to the node where the right child is to be inserted.
 * @value: The value to be placed in the new node.
 * Return: Pointer to the newly created node. Returns NULL in case of failure.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (!parent)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);

	new->n = value;
	new->left = NULL;

	if (parent->right == NULL)
	{
		new->parent = parent;
		new->right = NULL;
		parent->right = new;
	}
	else
	{
		new->parent = parent;
		new->right = parent->right;
		parent->right = new;
		new->right->parent = new;
	}
	return (new);
}
