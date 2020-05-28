#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - returns whether linked list is palindrome
 * @head: head of list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
  size_t i, size;
  listint_t *ptr, **reverse;
  int odd;

  if (head == NULL || *head == NULL || (**head).next == NULL)
    return (1);
  for (ptr = *head, size = 0; ptr != NULL; size++)
    ptr = ptr->next;
  if (size % 2)
    odd = 1;
  else
    odd = 0;
  size = size / 2;
  reverse = malloc(sizeof(*reverse) * size);
  for (ptr = *head, i = size; i > 0; i--)
    ptr = ptr->next;
  if (odd)
    ptr = ptr->next;
  for (i = size; i > 0; i--, ptr = ptr->next)
    reverse[i - 1] = ptr;
  for (ptr = *head, i = 0; i < size; i++, ptr = ptr->next)
    if (ptr->n != reverse[i]->n)
      return (0);
  return (1);
}
