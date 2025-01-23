import sys
from collections import defaultdict, deque

input = sys.stdin.readline
INT_MAX = sys.maxsize


N, M = map(int, input().split())
TABLE = [list(map(int, input().split())) for _ in range(N)]
COORDS = [list(map(int, input().split())) for _ in range(M)]

CUMSUM_TABLE = [[0 for _ in range(N)] for _ in range(N)]
CUMSUM_TABLE[0][0] = TABLE[0][0]
for i in range(N):
    for j in range(N):
        if i == 0 and j == 0:
            CUMSUM_TABLE[i][j] = TABLE[i][j]

        elif i == 0:
            CUMSUM_TABLE[i][j] = CUMSUM_TABLE[i][j - 1] + TABLE[i][j]

        elif j == 0:
            CUMSUM_TABLE[i][j] = CUMSUM_TABLE[i - 1][j] + TABLE[i][j]

        else:
            CUMSUM_TABLE[i][j] = (
                CUMSUM_TABLE[i - 1][j]
                + CUMSUM_TABLE[i][j - 1]
                - CUMSUM_TABLE[i - 1][j - 1]
                + TABLE[i][j]
            )

for x1, y1, x2, y2 in COORDS:
    if x1 >= 2 and y1 >= 2:
        print(
            CUMSUM_TABLE[x2 - 1][y2 - 1]
            - CUMSUM_TABLE[x2 - 1][y1 - 2]
            - CUMSUM_TABLE[x1 - 2][y2 - 1]
            + CUMSUM_TABLE[x1 - 2][y1 - 2]
        )
    elif y1 >= 2:
        print(CUMSUM_TABLE[x2 - 1][y2 - 1] - CUMSUM_TABLE[x2 - 1][y1 - 2])
    elif x1 >= 2:
        print(CUMSUM_TABLE[x2 - 1][y2 - 1] - CUMSUM_TABLE[x1 - 2][y2 - 1])
    else:
        print(CUMSUM_TABLE[x2 - 1][y2 - 1])
