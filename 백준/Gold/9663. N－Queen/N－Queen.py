import sys
from collections import deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())

isused1 = [False] * N  # Column
isused2 = [False] * (2 * N - 1)  # left,down to right,up diagonal
isused3 = [False] * (2 * N - 1)  # left.up to right,down diagonal

cnt = [0]


def Queen(nqueen: int):
    if nqueen == N:
        cnt[0] += 1
        return

    row = nqueen

    for col in range(N):
        if (
            not isused1[col]
            and not isused2[row + col]
            and not isused3[row - col + N - 1]
        ):
            isused1[col] = True
            isused2[row + col] = True
            isused3[row - col + N - 1] = True

            Queen(nqueen + 1)

            isused1[col] = False
            isused2[row + col] = False
            isused3[row - col + N - 1] = False


Queen(0)
print(cnt[0])
