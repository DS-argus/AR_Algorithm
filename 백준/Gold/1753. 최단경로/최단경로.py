import heapq as hq
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

V, E = map(int, input().split())
START = int(input())
EDGES = defaultdict(list)

for _ in range(E):
    u, v, w = map(int, input().split())
    EDGES[u].append((w, v))


# dijkstra
def dijkstra(start):
    heap = [(0, start)]

    visit = [False] * V
    COST = [sys.maxsize] * V
    COST[start - 1] = 0

    while heap:
        cost, node = hq.heappop(heap)

        if visit[node - 1]:
            continue

        visit[node - 1] = True

        for c, to in EDGES[node]:
            if not visit[to - 1] and COST[to - 1] > cost + c:
                COST[to - 1] = cost + c
                hq.heappush(heap, (cost + c, to))

    return COST


COST = dijkstra(START)

for c in COST:
    if c == sys.maxsize:
        print("INF")
    else:
        print(c)
