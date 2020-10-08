#include "menger.h"

/**
 * menger - draw 2D menger draw_sponge
 * @level: level to draw_sponge
 * Return: void
 */
void menger(int level)
{
	int size;
	int **grid;

	if (level < 0)
		return;
	size = pow(3, level);
	grid = alloc_grid(size, size);
	if (grid == NULL)
		return;
	fill_sponge(grid, 0, size, 0, size);
	draw_sponge(grid, size);
	free_grid(grid, size);
}

/**
 * fill_sponge - fill menger sponge grid
 * @grid: menger sponge array
 * @x_start: starting x coordinate
 * @x_end: ending x coordinate
 * @y_start: starting y coordinate
 * @y_end: ending y coordinate
 * Return: void
 */
void fill_sponge(int **grid, int x_start, int x_end, int y_start, int y_end)
{
	int step = (x_end - x_start) / 3;

	if (step == 0)
		grid[x_start][y_start] = 1;
	else
	{
		fill_sponge(grid, x_start, x_start + step,
			    y_start, y_start + step);
		fill_sponge(grid, x_start, x_start + step,
			    y_start + step, y_end - step);
		fill_sponge(grid, x_start, x_start + step,
			    y_end - step, y_end);
		fill_sponge(grid, x_start + step, x_start + step * 2,
			    y_start, y_start + step);
		fill_sponge(grid, x_start + step, x_start + step * 2,
			    y_end - step, y_end);
		fill_sponge(grid, x_end - step, x_end,
			    y_start, y_start + step);
		fill_sponge(grid, x_end - step, x_end,
			    y_start + step, y_end - step);
		fill_sponge(grid, x_end - step, x_end,
			    y_end - step, y_end);
	}
}

/**
 * draw_sponge - draw menger sponge
 * @grid: menger sponge array
 * @size: size of sponge array in rows and columns length
 * Return: void
 */
void draw_sponge(int **grid, int size)
{
	int i, x;

	for (i = 0; i < size; i++)
	{
		for (x = 0; x < size; x++)
		{
			if (grid[i][x])
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

/**
 * alloc_grid - allocate 2d array
 * @width: array width
 * @height: array height
 * Return: pointer to allocated space containing array else NULL
 */
int **alloc_grid(int width, int height)
{
	int i, x;
	int **grid;

	if (width <= 0 || height <= 0)
		return (NULL);
	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int *) * width);
		if (grid[i] == NULL)
		{
			free(grid);
			for (x = 0; x <= i; x++)
				free(grid[x]);
			return (NULL);
		}
		for (x = 0; x < width; x++)
			grid[i][x] = 0;
	}
	return (grid);
}

/**
 * free_grid - frees a 2d array
 * @grid: grid to free
 * @height: array height
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
