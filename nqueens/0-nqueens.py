#!/usr/bin/python3

import sys


def print_usage_and_exit(message):
    print(message)
    print("Usage: nqueens N")
    sys.exit(1)


def is_valid(N):
    try:
        N = int(N)
    except ValueError:
        print_usage_and_exit("N must be a number")

    if N < 4:
        print_usage_and_exit("N must be at least 4")

    return N


def solve_nqueens(N):
    solutions = []
    board = [-1] * N

    def is_safe(row, col):
        for prev_row in range(row):
            if (board[prev_row] == col or
                board[prev_row] - prev_row == col - row or
                    board[prev_row] + prev_row == col + row):
                return False
        return True

    def place_queens(row):
        if row == N:
            solutions.append([[i, board[i]] for i in range(N)])
            return
        for col in range(N):
            if is_safe(row, col):
                board[row] = col
                place_queens(row + 1)

    place_queens(0)
    return solutions


def main():
    if len(sys.argv) != 2:
        print_usage_and_exit("Usage: nqueens N")

    N = is_valid(sys.argv[1])
    solutions = solve_nqueens(N)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
