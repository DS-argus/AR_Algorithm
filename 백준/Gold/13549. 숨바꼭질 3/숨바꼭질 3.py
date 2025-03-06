import heapq as hq
import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, K = map(int, input().split())

V = 100_001

COST = [sys.maxsize] * V
visit = [False] * V

heap = [(0, N)]

while heap:
    time, node = hq.heappop(heap)

    if visit[node - 1]:
        continue

    if node == K:
        print(time)
        exit()

    visit[node - 1] = True

    if 0 <= node + 1 <= 100_000:
        # X+1
        if not visit[node] and COST[node] > time + 1:
            COST[node] = time + 1
            hq.heappush(heap, (COST[node], node + 1))

    if 0 <= node - 1 <= 100_000:
        # X-1
        if not visit[node - 2] and COST[node - 2] > time + 1:
            COST[node - 2] = time + 1
            hq.heappush(heap, (COST[node - 2], node - 1))

    if 0 <= 2 * node <= 100_000:
        # 2X
        if not visit[2 * node - 1] and COST[2 * node - 1] > time:
            COST[2 * node - 1] = time
            hq.heappush(heap, (COST[2 * node - 1], 2 * node))


print(-1)
