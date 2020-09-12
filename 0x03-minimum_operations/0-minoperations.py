#!/usr/bin/python3
import math

"""
calculates the fewest number of operations needed to result
in exactly n H characters
"""

def minOperations(n):
    sumOp = 0
    
    if n <= 1:
        return sumOp
    for i in range(2, int(math.sqrt(n) + 1)):
        while n % i == 0:
            sumOp += i
            n = n // i
    if n > 1:
        sumOp += n
    return sumOp

            
