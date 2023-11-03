#include "binary_trees.h"

/**
 * array_to_heap - Constructs a Max Binary Heap tree from an array.
 * @array: Builds a Max Binary Heap from an array using the first element's pointer.
 * @size: The count of elements in the array.
 *
 * Return: Returns the root node of the created Binary Heap or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
