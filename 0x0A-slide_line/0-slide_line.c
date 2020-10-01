#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: Pointer to array of integers containing elements
 * @size: size (number of) elements in array
 * @direction: either slide_left or slide_right
 * Return: 1 if success, otherwise 0
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t s;
	int pivot = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (s = 1; s < size && line[s] != 0; s++)
		{
			if (line[s - 1] == line[s])
			{
				line[s - 1] *= 2;
				line[s] = 0;
				pivot = 1;
			}
		}
		if (pivot)
			slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (s = size - 1; s > 0 && line[s - 1] != 0; s--)
		{
			if (line[s - 1] == line[s])
			{
				line[s] *= 2;
				line[s - 1] = 0;
				pivot = 1;
			}
		}
		if (pivot)
			slide_right(line, size);
	}
	else
	{
		return (0);
	}

	return (1);
}

/**
 *slide_right - slide the array of ints to right
 * @line: pointer to array of ints
 * @size: size (number of) elements in array
 * Return: void
 */
void slide_right(int *line, size_t size)
{
	int i, tmp;
	int curr = size - 1;

	for (i = size - 1; i >= 0 && curr >= 0; i--)
	{
		while (curr > 0 && line[curr] != 0)
			curr--;
		if (line[i] != 0 && i < (int) curr)
		{
			tmp = line[i];
			line[i] = line[curr];
			line[curr] = tmp;
		}
	}
}

/**
  * slide_left - slide the array of ints to left
  * @line: pointer to array of ints
  * @size: size (number of) elements in array
  * Return: void
  */
void slide_left(int *line, size_t size)
{
	int i, tmp;
	int curr = 0;

	for (i = 0; i < (int) size && curr < (int) size; i++)
	{
		while (line[curr] != 0)
			curr++;
		if (line[i] != 0 && i > curr)
		{
			tmp = line[i];
			line[i] = line[curr];
			line[curr] = tmp;
		}
	}
}
