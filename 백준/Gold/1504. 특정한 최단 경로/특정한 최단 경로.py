import heapq
import sys
from collections import defaultdict, deque

input = sys.stdin.readline

V, E = map(int, input().split())
EDGES = defaultdict(list)

for _ in range(E):
    a, b, c = map(int, input().split())
    EDGES[a].append((c, b))
    EDGES[b].append((c, a))

V1, V2 = map(int, input().split())


def dijkstra(start, end):
    DIST = [sys.maxsize] * V
    DIST[start - 1] = 0

    visit = [False] * V
    heap = [(0, start)]

    while heap:
        w, node = heapq.heappop(heap)

        if visit[node - 1]:
            continue

        visit[node - 1] = True

        for c, b in EDGES[node]:
            if visit[node - 1] and DIST[b - 1] > DIST[node - 1] + c:
                DIST[b - 1] = DIST[node - 1] + c
                heapq.heappush(heap, (DIST[b - 1], b))

    return DIST[end - 1]


p1 = dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, V)
p2 = dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, V)
if min(p1, p2) >= sys.maxsize:
    print(-1)
else:
    print(min(p1, p2))
