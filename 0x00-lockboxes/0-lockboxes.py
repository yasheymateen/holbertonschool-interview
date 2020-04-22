#!/usr/bin/env python3
""" method that determines if all boxes can be opened - lockboxes """


def canUnlockAll(boxes):
    """ function that uses keys/loops to determine if boxes can be opened """
    keys = {0}
    all_open = False

    while not all_open:
        unlocked = False
        for i in range(len(boxes)):
            if i in keys:
                for key in boxes[i]:
                    if key not in keys:
                        unlocked = True
                    keys.add(key)
        all_open = True if not unlocked else False
    if (len(keys) == len(boxes)):
        return True
    else:
        return False
