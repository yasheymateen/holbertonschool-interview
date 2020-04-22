#!/usr/bin/env python3
""" method that determines if all boxes can be opened - lockboxes """


def canUnlockAll(boxes):
    """ figures out if all boxes can be opened """
    checked = [False for i in range(len(boxes))]
    checked[0] = True
    stack = [0]
    while len(stack):
        box = stack.pop(0)
        for b in boxes[box]:
            if isinstance(b, int) and b >= 0 and b < len(boxes) and not checked[b]:
                checked[b] = True
                stack.append(b)
    return all(checked)
