#!/usr/bin/python3
""" UTF 8-Validation """


def byte_count(n):
    """ counts bytes from encoding """
    count = 0
    i = 7
    while n & 1 << i:
        count += 1
        i -= 1
    return count


def validUTF8(data):
    """ determines if given data set represents valid UTF8 encoding """
    if type(data) != list:
        return False
    i = 0
    while i < len(data):
        if data[i] < 1 << 7:
            i += 1
        else:
            if data[i] > 255:
                return False
            number_bytes = byte_count(data[i])
            if i + number_bytes > len(data):
                return False
            else:
                for j in range(1, number_bytes):
                    if byte_count(data[i + j]) != 1:
                        return False
                i += number_bytes
                if i > len(data):
                    return False
    return True
