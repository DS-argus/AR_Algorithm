import heapq as hq
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M, X = map(int, input().split())

EDGES = defaultdict(list)

for _ in range(M):
    fr, to, time = map(int, input().split())

    EDGES[fr].append((time, to))

goparty = [0] * N
backhome = [0] * N

# Sparse하기 때문에, dijkstra를 V번 돌려도 충분
# O(V * E * log(V))
for start in range(1, N + 1):
    # start에서 시작해서 다른 vertex 방문하는 shortest path
    # start dijkstra
    heap = [(0, start)]

    COST = [sys.maxsize] * N
    COST[start - 1] = 0

    visit = [False] * N

    while heap:
        cost, node = hq.heappop(heap)

        if visit[node - 1]:
            continue

        visit[node - 1] = True

        for time, to in EDGES[node]:
            if not visit[to - 1] and COST[to - 1] > cost + time:
                COST[to - 1] = cost + time
                hq.heappush(heap, (COST[to - 1], to))

    if start == X:
        backhome = COST
    else:
        goparty[start - 1] = COST[X - 1]

total = [a + b for (a, b) in zip(goparty, backhome)]

print(max(total))
