# 0x0A - 2048 (single line)

## Slide Line
* The goal of this task is to reproduce the 2048 game(NSFW!!) mechanics on a single horizontal line.

## Requirements
* Given an array of integers, slide & merge them to the left or right.
* Identical numbers, whether contiguous or separated by zeros, should be merged

## Prototype
* `int slide_line(int *line, size_t, size, int direction);`
* `line` points to an array of integers containing `size` elements to be slided & merged to
* `direction`, represented by direction, which can be either: `SLIDE_LEFT` or `SLIDE_RIGHT`

## Usage
* `gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c`
* `./0-slide_line L 2 2 0 0`
- Output:
`Line: 2, 2, 0, 0`
`Slide to the left`
`Line: 4, 0, 0, 0`

## Author
* **Yashar Mateen** - [yasheymateen](https://www.github.com/yasheymateen)
