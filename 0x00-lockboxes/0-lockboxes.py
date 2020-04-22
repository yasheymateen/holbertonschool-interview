#!/usr/bin/env python3
""" method that determines if all boxes can be opened - lockboxes """


def canUnlockAll(boxes):
    pile = [0]
    unlocked = [1] + [0] * (len(boxes) - 1)
    i = 0

    if len(boxes) == 0:
        return True
    if not isinstance(boxes, list):
        return False
    while pile:
        k = pile.pop()
        for key in boxes[k]:
            if key > 0 and key < len(boxes) and unlocked[key] == 0:
                unlocked[key] = 1
                pile.append(key)
        i = i + 1

    if 0 in unlocked:
        return False
    else:
        return True
