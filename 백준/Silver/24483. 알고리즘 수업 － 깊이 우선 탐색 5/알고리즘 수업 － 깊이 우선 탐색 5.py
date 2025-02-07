import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

from collections import defaultdict, deque

N, M, R = map(int, input().split())

EDGES = [tuple(map(int, input().split())) for _ in range(M)]
EDGES.sort(key=lambda x: (x[0], x[1]))

adj = defaultdict(list)

for a, b in EDGES:
    adj[a].append(b)
    adj[b].append(a)

depth = [-1] * N
visit_order = [0] * N
order = [0]


def dfs(start: int, d: int):

    depth[start - 1] = d
    order[0] += 1
    visit_order[start - 1] = order[0]

    for neighbor in adj[start]:
        if depth[neighbor - 1] == -1:
            dfs(neighbor, d + 1)


dfs(R, 0)

ans = 0
for i in range(N):
    ans += depth[i] * visit_order[i]

print(ans)
