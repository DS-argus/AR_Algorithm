import sys

input = sys.stdin.readline
INF = sys.maxsize

from collections import defaultdict, deque


def print_BFS(V: int, NEIGHBORS: dict):
    q = deque([V])
    visit = []
    while q:
        cnt = q.popleft()
        if cnt in visit:
            continue
        visit.append(cnt)

        neighbors = NEIGHBORS[cnt]
        for neighbor in neighbors:
            if neighbor in visit:
                continue
            q.append(neighbor)

    print(*visit)


def print_DFS(V: int, NEIGHBORS: dict):
    visit = [V]

    neighbors = NEIGHBORS[V]
    for neighbor in neighbors:
        sub_DFS(neighbor, NEIGHBORS, visit)

    print(*visit)


def sub_DFS(V: int, NEIGHBORS: dict, visit: list):
    if V in visit:
        return

    visit.append(V)

    neighbors = NEIGHBORS[V]
    for neighbor in neighbors:
        sub_DFS(neighbor, NEIGHBORS, visit)


N, M, V = map(int, input().split())
NEIGHBORS = defaultdict(list)

for _ in range(M):
    a, b = map(int, input().split())
    NEIGHBORS[a].append(b)
    NEIGHBORS[b].append(a)

for _, v in NEIGHBORS.items():
    v.sort()


print_DFS(V, NEIGHBORS)
print_BFS(V, NEIGHBORS)
