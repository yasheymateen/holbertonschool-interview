#include "lists.h"
/**
 * check_cycle - checks linked list for cycle in it
 * @list: linked list
 * Return: 0 if no cycle, otherwise 1
 */
int check_cycle(listint_t *list)
{
  listint_t *fast, *slow;

  if (list == NULL)
    return (0);
  fast = slow = list;
  do {
    fast = fast->next;
    if (fast == NULL)
      return (0);
    fast = fast->next;
    if (fast == NULL)
      return (0);
    slow = slow->next;
  } while (fast != slow);
  return (1);
}
