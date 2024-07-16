#!/usr/bin/python3
""" UTF-8 Validation """

def validUTF8(data):
    """ Determines if a given data set represents a valid UTF-8 encoding """
    num_bytes = 0

    for num in data:
        if num_bytes == 0:
            mask = 1 << 7
            while mask & num:
                num_bytes += 1
                mask >>= 1

            if num_bytes == 0 or num_bytes > 4:
                return False

            if num_bytes > 1:
                num_bytes -= 1
        else:
            if (num >> 6) != 0b10:
                return False

            num_bytes -= 1

    if num_bytes > 0:
        return False

    return True
