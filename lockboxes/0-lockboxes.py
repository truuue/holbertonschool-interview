#!/usr/bin/python3

"""
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    key = [0]
    for k in key:
        for i in boxes[k]:
            if i not in key and i < len(boxes):
                key.append(i)
    if len(key) == len(boxes):
        return True
    return False
