import sys

input = sys.stdin.readline
INF = sys.maxsize

from collections import deque
from copy import deepcopy


def findArea(GRID: list[str]) -> int:
    area = 0
    N = len(GRID)

    for i in range(N):
        for j in range(N):
            if GRID[i][j] == "C":
                continue

            START = GRID[i][j]

            q = deque([(i, j)])
            visit = [(i, j)]

            while q:
                r, c = q.popleft()
                GRID[r] = GRID[r][:c] + "C" + GRID[r][c + 1 :]
                # assert GRID[r][c] == "C" and len(GRID[r]) == N

                for nr, nc in get_next_moves(r, c, N):
                    if GRID[nr][nc] == START and not (nr, nc) in visit:
                        q.append((nr, nc))
                        visit.append((nr, nc))

            area += 1

    return area


def get_next_moves(row: int, col: int, N: int):
    MOVE = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    for dr, dc in MOVE:
        nr, nc = row + dr, col + dc
        if 0 <= nr < N and 0 <= nc < N:
            yield nr, nc


N = int(input())
GRID = [input().split()[0] for _ in range(N)]

GRID2 = deepcopy(GRID)
result = [findArea(GRID)]
for i in range(N):
    GRID2[i] = GRID2[i].replace("G", "R")

result.append(findArea(GRID2))
print(*result)
