import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

import heapq
from collections import defaultdict, deque

V, E = map(int, input().split())

EDGES = defaultdict(list)
for _ in range(E):
    a, b, w = map(int, input().split())
    EDGES[a].append((w, b))
    EDGES[b].append((w, a))


visited = set()
pq = [(0, 1)]
sum_w = 0

while pq:
    w, node = heapq.heappop(pq)

    if node in visited:
        continue

    visited.add(node)
    sum_w += w

    for edge_w, neighbor in EDGES[node]:
        if neighbor not in visited:
            heapq.heappush(pq, (edge_w, neighbor))

print(sum_w)
