#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif
