import heapq as hq
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())
EDGES = defaultdict(list)

for _ in range(M):
    u, v, w = map(int, input().split())
    EDGES[u].append((w, v))
    # EDGES[v].append((w, u))


def bellman_ford(start):
    COST = [sys.maxsize] * N
    COST[start - 1] = 0

    for i in range(N):

        for u, edges in EDGES.items():
            for cost, v in edges:
                if COST[u-1] != sys.maxsize and COST[v - 1] > COST[u - 1] + cost:
                    # negative cycle
                    if i == N - 1:
                        print(-1)
                        exit()

                    COST[v - 1] = COST[u - 1] + cost

    return COST


COST = bellman_ford(1)

for c in COST[1:]:
    if c == sys.maxsize:
        print(-1)
    else:
        print(c)
