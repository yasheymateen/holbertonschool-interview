#include <stdio.h>
#include "sandpiles.h"
/**
 * tumble_square - tumble sandpile square grid
 * @grid: grid
 * @row: row
 * @col: column
 * Return: void
 */
void tumble_square(int grid[3][3], int row, int col)
{
  grid[row][col] -= 4;
  if (row > 0)
    grid[row - 1][col] += 1;
  if (row < 2)
    grid[row + 1][col] += 1;
  if (col > 0)
    grid[row][col - 1] += 1;
  if (col < 2)
    grid[row][col + 1] += 1;
}

/**
 * _print_grid - print grid
 * @grid: grid
 */
void _print_grid(int grid[3][3])
{
  int row, col;

  for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
      if (col < 2)
	printf("%d ", grid[row][col]);
      else
	printf("\n");
    }
  }
}

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: first grid
 * @grid2: 2nd grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
  int tumbled = 1, row, col;

  for (row = 0; row < 3; row++)
    for (col = 0; col < 3; col++K)
      grid1[row][col] += grid2[row][col];
  while (tumbled) {
    for (row = 0; row < 3; row++)
      for (col = 0; col < 3; col++)
	grid2[row][col] = grid1[row][col];
    tumbled = 0;
    for (row = 0; row < 3; row++)
      for (col = 0; col < 3; col++)
	if (grid2[row][col] > 3) {
	  tumble_square(grid1, row, col);
	  tumbled = 1;
	}
    if (tumbled) {
      printf("=\n");
      _print_grid(grid2);
    }
  }
}
