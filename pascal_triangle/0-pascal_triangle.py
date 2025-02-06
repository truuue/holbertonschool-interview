#!/usr/bin/python3
"""
Module for generating Pascal's triangle
"""


def pascal_triangle(n):
    """
    Generate Pascal's triangle up to level n
    Args:
        n (int): number of levels of the triangle
    Returns:
        list: list of lists representing Pascal's triangle
    """
    result = []
    if n <= 0:
        return result

    result.append([1])

    for level in range(n - 1):
        current_line = [1]
        previous_line = result[-1]

        for pos in range(len(previous_line) - 1):
            somme = previous_line[pos] + previous_line[pos + 1]
            current_line.append(somme)

        current_line.append(1)
        result.append(current_line)

    return result
