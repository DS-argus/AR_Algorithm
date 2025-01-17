import sys
from typing import Iterator

input = sys.stdin.readline

from collections import defaultdict, deque

N = int(input())
num_edge = int(input())

edges = defaultdict(list, [])

for _ in range(num_edge):
    a, b = map(int, input().split())

    edges[a].append(b)
    edges[b].append(a)

visits = set()

q = deque([1])
visits.add(1)
while q:
    cnt = q.popleft()

    neighbors = edges[cnt]

    for neighbor in neighbors:
        if not neighbor in visits:
            q.append(neighbor)
            visits.add(neighbor)

print(len(visits) - 1)
