#!/usr/bin/python3
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
        return len(keys) == len(boxes)

"""
def canUnlockAll(boxes):
     figures out if all boxes can be opened 
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
"""
