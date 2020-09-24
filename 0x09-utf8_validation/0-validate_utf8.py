#!/usr/bin/python3
""" UTF 8-Validation """


def validUTF8(data):
    """ determines if given data set represents valid UTF8 encoding """
    byte_count = 0
    first = 1 << 7
    second = 1 << 6

    for n in data:
        condition = 1 << 7
        if byte_count == 0:
            while condition & n:
                byte_count += 1
                condition = condition >> 1
            if byte_count == 0:
                continue
            if byte_count == 1 or byte_count > 4:
                return False
        else:
            if not (n & first and not (n & second)):
                return False
        byte_count -= 1
    return byte_count == 0
