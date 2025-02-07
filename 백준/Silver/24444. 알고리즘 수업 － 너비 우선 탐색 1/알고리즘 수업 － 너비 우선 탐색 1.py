import sys

input = sys.stdin.readline

from collections import defaultdict, deque

N, M, R = map(int, input().split())

EDGES = [tuple(map(int, input().split())) for _ in range(M)]
EDGES.sort(key=lambda x: (x[0], x[1]))

adj = defaultdict(list)

for a, b in EDGES:
    adj[a].append(b)
    adj[b].append(a)

visit_order = [0] * N
visit_order[R - 1] = 1
q = deque([R])
order = 1
while q:
    cnt = q.popleft()

    for neighbor in adj[cnt]:
        if visit_order[neighbor - 1] == 0:
            q.append(neighbor)
            visit_order[neighbor - 1] = order + 1
            order += 1

for v in visit_order:
    print(v)
