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


def dfs(start: int, d: int):

    depth[start - 1] = d

    for neighbor in adj[start]:
        if depth[neighbor - 1] == -1:
            dfs(neighbor, d + 1)


dfs(R, 0)

for v in depth:
    print(v)
