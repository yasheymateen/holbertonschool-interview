#include <stdio.h>
#include "sandpiles.h"


/**
 * print_grid - print the sandpile.
 *
 * @grid: the sandpile.
 * Return: void.
 *
 */
static void print_grid(int grid[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (j)
printf(" ");
printf("%d", grid[i][j]);
	}
printf("\n");
}
}

/**
 * check - check if the sandpile could be toppling.
 *
 * @grid: the sandpile.
 * @grid2: another grid for save the initial condiction.
 * Return: 0 if it could be, 1 if doesn't.
 *
 */
int check(int grid[3][3], int grid2[3][3])
{
int i, j, flag = 1;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
flag = 0;
grid2[i][j] = 1;
}
else
{
grid2[i][j] = 0;
}
}
}
return (flag);
}


/**
 * toppling - toppling round the sandpile.
 *
 * @grid: the sandpile.
 * @grid2: another grid for save the initial condiction.
 * Return: void.
 *
 */
void toppling(int grid[3][3], int grid2[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
if (grid[i][j] > 3 && grid2[i][j] == 1)
{
grid[i][j] -= 4;
if (i - 1 >= 0)
grid[i - 1][j] += 1;
if (i + 1 <= 2)
grid[i + 1][j] += 1;
if (j - 1 >= 0)
grid[i][j - 1] += 1;
if (j + 1 <= 2)
grid[i][j + 1] += 1;
}
}
}
}


/**
 * sandpiles_sum - compute the sum of two sandpiles.
 *
 * @grid1: first sandpile.
 * @grid2: second sandpile.
 * Return: void.
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
int i, j;

for (i = 0; i < 3; i++)
{
for (j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}

while (check(grid1, grid2) == 0)
{
printf("=\n");
print_grid(grid1);
toppling(grid1, grid2);
}
}
