#!/usr/bin/python3
"""
Rotate 2d matrix
"""


def rotate_2d_matrix(matrix):
    """rotate 2d matrix"""
    leng = len(matrix[0])

    for i in range(leng - 1, -1, -1):
        for j in range(0, leng):
            matrix[j].append(matrix[i].pop(0))
