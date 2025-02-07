import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

from collections import defaultdict, deque

N, M, R = map(int, input().split())

EDGES = [tuple(map(int, input().split())) for _ in range(M)]
EDGES.sort(key=lambda x: (x[0], x[1]), reverse=True)

adj = defaultdict(list)

for a, b in EDGES:
    adj[a].append(b)
    adj[b].append(a)

visit_order = [0] * N

order = [0]


def dfs(start: int):

    order[0] += 1
    visit_order[start - 1] = order[0]

    for neighbor in adj[start]:
        if visit_order[neighbor - 1] == 0:
            dfs(neighbor)


dfs(R)

for v in visit_order:
    print(v)
