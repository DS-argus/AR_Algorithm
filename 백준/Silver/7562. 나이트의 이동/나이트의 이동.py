import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

from collections import defaultdict, deque

N = int(input())


def valid_moves(I: int, i: int, j: int):
    MOVES = [(-2, 1), (-1, 2), (2, 1), (1, 2), (2, -1), (1, -2), (-1, -2), (-2, -1)]

    for di, dj in MOVES:
        ni, nj = i + di, j + dj
        if 0 <= ni < I and 0 <= nj < I:
            yield (ni, nj)


for _ in range(N):

    I = int(input())

    start = tuple(map(int, input().split()))
    end = tuple(map(int, input().split()))

    # 못 도달하는 경우는 없나?
    ans = sys.maxsize

    visit = set()

    q = deque([(start[0], start[1], 0)])
    visit.add(start)

    while q:
        ci, cj, n = q.popleft()

        if (ci, cj) == end:
            print(n)
            break

        for ni, nj in valid_moves(I, ci, cj):
            if (ni, nj) not in visit:
                q.append((ni, nj, n + 1))
                visit.add((ni, nj))
