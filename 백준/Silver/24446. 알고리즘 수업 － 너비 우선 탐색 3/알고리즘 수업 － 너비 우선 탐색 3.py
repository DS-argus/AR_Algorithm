import sys

input = sys.stdin.readline

from collections import defaultdict, deque

N, M, R = map(int, input().split())

EDGES = [tuple(map(int, input().split())) for _ in range(M)]
EDGES.sort(key=lambda x: (x[0], x[1]), reverse=True)

adj = defaultdict(list)

for a, b in EDGES:
    adj[a].append(b)
    adj[b].append(a)

depth = [-1] * N
depth[R - 1] = 0
q = deque([(R, 0)])
while q:
    cnt, d = q.popleft()

    for neighbor in adj[cnt]:
        if depth[neighbor - 1] == -1:
            q.append((neighbor, d + 1))
            depth[neighbor - 1] = d + 1

for v in depth:
    print(v)
