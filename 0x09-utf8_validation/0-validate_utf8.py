#!/usr/bin/python3
""" UTF 8-Validation """

from itertools import takewhile


def bit_count(bytes):
    """ counts bits from encoding """
    for byte in bytes:
        n = []
        exp = 1 << 8
        while exp:
            exp >>= 1
            n.append(bool(byte & exp))
            yield n


def validUTF8(data):
    """ determines if given data set represents valid UTF8 encoding """
    bits = bit_count(data)
    for byte in bits:
        if byte[0] == 0:
            continue
        amt = sum(takewhile(bool, byte))
        if amt <= 1:
            return False
        if amt >= 4:
            return False

        for _ in range(amt - 1):
            try:
                byte = next(bits)
            except StopIteration:
                return False
            if byte[0:2] != [1, 0]:
                return False
    return True
