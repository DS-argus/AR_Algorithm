import sys

input = sys.stdin.readline

N, r, c = map(int, input().split())

size = 2**N


def split_area(size, start_r, start_c, r, c) -> int:
    if size == 2:
        if r - start_r == 1 and c - start_c == 1:
            return 3
        elif r - start_r == 1:
            return 2
        elif c - start_c == 1:
            return 1
        else:
            return 0

    ssize = size // 2

    if r < start_r + ssize and c < start_c + ssize:
        return 0 + split_area(ssize, start_r, start_c, r, c)

    elif r < start_r + ssize and c >= start_c + ssize:
        return ssize**2 + split_area(ssize, start_r, start_c + ssize, r, c)

    elif r >= start_r + ssize and c < start_c + ssize:
        return ssize**2 * 2 + split_area(ssize, start_r + ssize, start_c, r, c)

    else:
        return ssize**2 * 3 + split_area(ssize, start_r + ssize, start_c + ssize, r, c)


print(split_area(size, 0, 0, r, c))
