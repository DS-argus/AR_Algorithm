import sys

input = sys.stdin.readline

from collections import defaultdict, deque


def valid_moves(w, h, i, j):
    MOVES = [(1, 0), (-1, 0), (0, 1), (0, -1), (1, 1), (1, -1), (-1, 1), (-1, -1)]

    for di, dj in MOVES:
        ni, nj = i + di, j + dj
        if 0 <= ni < h and 0 <= nj < w:
            yield (ni, nj)


def find_island(territory: list) -> int:
    w, h = len(territory[0]), len(territory)

    count = 0
    for i in range(h):
        for j in range(w):
            if territory[i][j] == 1:
                count += 1

                stack = [(i, j)]

                while stack:
                    cnt_i, cnt_j = stack.pop()
                    territory[cnt_i][cnt_j] = 0

                    for ni, nj in valid_moves(w, h, cnt_i, cnt_j):
                        if territory[ni][nj] == 1:
                            stack.append((ni, nj))

    return count


while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break

    islands = [list(map(int, input().split())) for _ in range(h)]

    print(find_island(islands))
