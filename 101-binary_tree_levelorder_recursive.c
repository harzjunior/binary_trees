#include "binary_trees.h"

/**
 * struct node_s - A singly linked list
 * @node: Constant binary tree node.
 * @next: Refers to the subsequent node.
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: A pointer to the root node of the tree for the traversal.
 * @func: A pointer to a function to be invoked for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Calls func on all nodes at each level.
 * @head: Pointer to the head of a linked list with nodes at the same level.
 * @func: A pointer to a function that will be called for each node.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - Appends the children of a parent to a linked list.
 * @head: A pointer to the head of the linked list where children will be added.
 * @parent: A pointer to the node whose children are to be appended.
 * Return: A pointer to the head of a linked list containing children.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - Appends a new node to the end of a linked list.
 * @head: Pointer to the head of the linked list.
 * @btnode: constant binary tree node to append
 * Return: A pointer to the head, or NULL in case of failure.
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - Deallocates all the nodes in a linked list.
 * @head: A pointer to the head of a linked list named list_t.
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
