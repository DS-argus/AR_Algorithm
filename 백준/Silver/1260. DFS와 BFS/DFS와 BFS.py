import sys

input = sys.stdin.readline
INF = sys.maxsize

from collections import defaultdict, deque


def print_BFS(V: int, edges: dict):
    q = deque([V])
    visit = []
    while q:
        cnt = q.popleft()
        if cnt in visit:
            continue
        visit.append(cnt)

        neighbors = edges[cnt]
        for neighbor in neighbors:
            if neighbor in visit:
                continue
            q.append(neighbor)

    print(*visit)


def print_DFS(V: int, edges: dict):
    visit = [V]

    neighbors = edges[V]
    for neighbor in neighbors:
        sub_DFS(neighbor, edges, visit)

    print(*visit)


def sub_DFS(V: int, edges: dict, visit: list):
    if V in visit:
        return

    visit.append(V)

    neighbors = edges[V]
    for neighbor in neighbors:
        sub_DFS(neighbor, edges, visit)


N, M, V = map(int, input().split())
EDGES = [tuple(map(int, input().split())) for _ in range(M)]

EDGE_dict = defaultdict(list)
for a, b in EDGES:
    EDGE_dict[a].append(b)
    EDGE_dict[b].append(a)

for k, v in EDGE_dict.items():
    v.sort()

print_DFS(V, EDGE_dict)
print_BFS(V, EDGE_dict)
