#!/usr/bin/python3


def minOperations(n):
    """ Method to calculate fewest # of opertions needed to result in n H chars """

    if n <= 1:
        return 0
    for x in range(2, n + 1):
        if n % x == 0:
            return minOperations(int(n / x)) + x
