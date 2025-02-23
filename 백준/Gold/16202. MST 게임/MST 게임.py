import heapq
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M, K = map(int, input().split())

EDGES = defaultdict(list)

for i in range(M):
    fr, to = map(int, input().split())
    weight = i + 1

    EDGES[fr].append((weight, to))
    EDGES[to].append((weight, fr))


def make_MST(N, EDGES):
    # Kruskal algorithm
    visited = set()
    pq = [(0, 1)]
    weight_sum = 0
    selected = []

    while pq:
        w, node = heapq.heappop(pq)

        if node in visited:
            continue

        visited.add(node)
        weight_sum += w
        selected.append((w, node))

        for edge_w, neighbor in EDGES[node]:
            if neighbor not in visited:
                heapq.heappush(pq, (edge_w, neighbor))

    selected.remove((0, 1))
    if len(selected) != N - 1:
        weight_sum = 0

    return selected, weight_sum


isZero = False
for _ in range(K):
    if isZero:
        print(0)
        continue

    selected, weight_sum = make_MST(N, EDGES)
    if weight_sum == 0:
        isZero = True
        print(weight_sum)
        continue
    else:
        print(weight_sum)
        selected.sort()
        minimum_weight = selected[0][0]

        for fr, edges in EDGES.items():
            for idx, (weight, to) in enumerate(edges):
                if weight == minimum_weight:
                    edges.remove(edges[idx])
