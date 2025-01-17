import sys
from typing import Iterator

input = sys.stdin.readline

from collections import defaultdict, deque

N, M = map(int, input().split())
edges = defaultdict(list, [])
for _ in range(M):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

visits = set()
CC = 0
for node in range(1, N + 1):
    if not node in visits:
        CC += 1
        q = deque([node])
        visits.add(node)

        while q:
            cnt = q.popleft()

            neighs = edges[cnt]

            for neigh in neighs:
                if not neigh in visits:
                    q.append(neigh)
                    visits.add(neigh)

print(CC)
