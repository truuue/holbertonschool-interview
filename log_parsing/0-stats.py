#!/usr/bin/python3
import sys
""" Module to parse logs """


def parse_logs():
    """ Function to parse logs """
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0
    """ Parse logs """

    try:
        """ Read line by line from stdin """
        for line in sys.stdin:
            """ Split line by spaces """
            parts = line.split()
            if len(parts) < 2:
                """ Skip lines that don't have status code and file size"""
                continue

            status_code = int(parts[-2])
            file_size = int(parts[-1])

            total_size += file_size
            status_codes[status_code] += 1
            line_count += 1

            if line_count % 10 == 0:
                """ Print log stats """
                print("Total file size:", total_size)
                for code in sorted(status_codes.keys()):
                    """ Print status codes """
                    if status_codes[code] > 0:
                        """ Print status codes """
                        print(f"{code}: {status_codes[code]}")

    except KeyboardInterrupt:
        """ Print log stats """
        print("Total file size:", total_size)
        for code in sorted(status_codes.keys()):
            """ Print status codes """
            if status_codes[code] > 0:
                """ Print status codes """
                print(f"{code}: {status_codes[code]}")


if __name__ == "__main__":
    """ Main Function """
    parse_logs()
