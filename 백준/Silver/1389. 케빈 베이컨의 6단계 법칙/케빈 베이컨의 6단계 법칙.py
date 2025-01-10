import sys

input = sys.stdin.readline

N, M = map(int, input().split())
EDGES = [tuple(map(int, input().split())) for _ in range(M)]

DISTANCE = [[sys.maxsize for _ in range(N)] for _ in range(N)]
for i in range(N):

    DISTANCE[i][i] = 0

for EDGE in EDGES:
    fr, to = EDGE

    DISTANCE[fr - 1][to - 1] = 1
    DISTANCE[to - 1][fr - 1] = 1

for base in range(N):
    for fr in range(N):
        for to in range(N):
            DISTANCE[base][to] = min(
                DISTANCE[base][to], DISTANCE[base][fr] + DISTANCE[fr][to]
            )
            DISTANCE[to][base] = DISTANCE[base][to]

values = [sum(DISTANCE[i]) for i in range(N)]

min_value = min(values)

for i in range(N):
    if values[i] == min_value:
        print(i + 1)
        break
