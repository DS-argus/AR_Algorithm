import heapq as hq
import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())
M = int(input())

adj = defaultdict(list)

for _ in range(M):
    a, b, w = map(int, input().split())
    adj[a].append((w, b))

start, end = map(int, input().split())


def dijkstra(start):
    heap = [(0, start)]

    COST = [sys.maxsize] * N
    COST[start - 1] = 0

    visit = [False] * N

    while heap:
        cost, node = hq.heappop(heap)

        if visit[node - 1]:
            continue

        visit[node - 1] = True

        for time, to in adj[node]:
            if not visit[to - 1] and COST[to - 1] > cost + time:
                COST[to - 1] = cost + time
                hq.heappush(heap, (COST[to - 1], to))

    return COST


print(dijkstra(start)[end - 1])
