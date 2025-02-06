#!/usr/bin/python3
"""Module for prime number game implementation"""


def is_prime(n):
    """Check if number is prime"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def update_prime_list(max_val, prime_cache):
    """Update list of prime numbers up to max_val"""
    last_checked = prime_cache[-1]
    if max_val > last_checked:
        for num in range(last_checked + 1, max_val + 1):
            prime_cache.append(num if is_prime(num) else 0)


def isWinner(x, nums):
    """
    Determine winner of prime number game

    Args:
        x: number of rounds to play
        nums: list of n values for each round

    Returns:
        str: 'Maria' or 'Ben' based on winner, None if tie
    """
    if not nums or x < 1:
        return None

    results = {"Maria": 0, "Ben": 0}
    prime_cache = [0, 0, 2]

    update_prime_list(max(nums), prime_cache)

    for round_n in range(x):
        prime_count = sum(1 for p in prime_cache[:nums[round_n] + 1]
                          if p != 0 and p <= nums[round_n])

        winner = "Maria" if prime_count % 2 == 1 else "Ben"
        results[winner] += 1

    if results["Maria"] > results["Ben"]:
        return "Maria"
    elif results["Ben"] > results["Maria"]:
        return "Ben"
    return None
