#!/usr/bin/python3
'''Making Change module'''


def makeChange(coins, total):
    """
    Function that given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total
    """
    if total <= 0:
        return 0

    # Initialiser un tableau pour stocker les résultats intermédiaires
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # Remplir le tableau dp
    for i in range(1, total + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    # Si le montant total ne peut pas être atteint
    if dp[total] == float('inf'):
        return -1

    return dp[total]
