#!/usr/bin/python3
""" Shebang line """
import sys
""" Module to parse logs """

""" Function to parse logs """


def parse_logs():
    """ Function to parse logs """
    total_size = 0
    """ Total file size """
    status_codes = {200: 0, 301: 0, 400: 0,
                    401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    """ Status codes """
    line_count = 0
    """ Parse logs """

    """ Try block to read from stdin """
    try:
        """ Read line by line from stdin """
        for line in sys.stdin:
            """ Split line by spaces """
            parts = line.split()
            """ Skip lines that don't have status code and file size """
            if len(parts) < 2:
                """ Skip lines that don't have status code and file size"""
                continue

            status_code = int(parts[-2])
            """ Get status code """
            file_size = int(parts[-1])
            """ Get file size """

            total_size += file_size
            """ Add file size to total size """
            status_codes[status_code] += 1
            """ Add status code to status codes """
            line_count += 1
            """ Increment line count """

            if line_count % 10 == 0:
                """ Print log stats """
                print("Total file size:", total_size)
                """ Print log stats """
                for code in sorted(status_codes.keys()):
                    """ Print status codes """
                    if status_codes[code] > 0:
                        """ Print status codes """
                        print(f"{code}: {status_codes[code]}")
                        """ Print status codes """

    except KeyboardInterrupt:
        """ Print log stats """
        print("Total file size:", total_size)
        """ Print log stats """
        for code in sorted(status_codes.keys()):
            """ Print status codes """
            if status_codes[code] > 0:
                """ Print status codes """
                print(f"{code}: {status_codes[code]}")
                """ Print status codes """


if __name__ == "__main__":
    """ Main Function """
    parse_logs()
    """ Parse logs """
