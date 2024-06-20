#!/usr/bin/python3
import sys
""" Module to parse logs """


def parse_logs():
    """ Function to parse logs """
    total_size = 0
    status_codes = {200: 0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) < 2:
                continue

            status_code = int(parts[-2])
            file_size = int(parts[-1])

            total_size += file_size
            status_codes[status_code] += 1
            line_count += 1

            if line_count % 10 == 0:
                print("Total file size:", total_size)
                for code in sorted(status_codes.keys()):
                    if status_codes[code] > 0:
                        print(f"{code}: {status_codes[code]}")

    except KeyboardInterrupt:
        print("Total file size:", total_size)
        for code in sorted(status_codes.keys()):
            if status_codes[code] > 0:
                print(f"{code}: {status_codes[code]}")


if __name__ == "__main__":
    """ Main Function """
    parse_logs()
