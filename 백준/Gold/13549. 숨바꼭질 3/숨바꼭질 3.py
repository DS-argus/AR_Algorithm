import heapq as hq
import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, K = map(int, input().split())

V = 100_001  # 최대 범위
COST = [sys.maxsize] * V

heap = [(0, N)]
COST[N] = 0  # 시작점 비용 0

while heap:
    time, node = hq.heappop(heap)

    if node == K:
        print(time)
        exit()

    # ✅ 순간이동 (가중치 0)
    if 2 * node <= 100_000 and COST[2 * node] > time:
        COST[2 * node] = time
        hq.heappush(heap, (time, 2 * node))

    # ✅ X+1 (가중치 1)
    if node < 100_000 and COST[node + 1] > time + 1:
        COST[node + 1] = time + 1
        hq.heappush(heap, (time + 1, node + 1))

    # ✅ X-1 (가중치 1)
    if node > 0 and COST[node - 1] > time + 1:
        COST[node - 1] = time + 1
        hq.heappush(heap, (time + 1, node - 1))

print(-1)