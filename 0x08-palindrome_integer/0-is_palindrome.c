#include "palindrome.h"
/**
 * is_palindrome - checks whether unsigned int is pal
 * @n: number to check
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
  unsigned long rem, num, rev = 0;
  num = n;

  while (n > 0)
    {
      rem = n % 10;
      rev = rev * 10 + rem;
      n /= 10;
    }
  if (rev == num)
    return (1);
  else
    return (0);
}
