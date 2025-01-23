import sys

input = sys.stdin.readline

from collections import defaultdict, deque

N = int(input())
EDGES = defaultdict(list, [])
for _ in range(N - 1):
    a, b = map(int, input().split())
    EDGES[a].append(b)
    EDGES[b].append(a)

q = deque([1])
visits = {1}
PA_list = [0] * N
PA_list[0] = 1
while q:
    cnt = q.popleft()

    # cnt의 pa가 있으면,
    children = EDGES[cnt]

    for child in children:
        if not child in visits:
            PA_list[child - 1] = cnt
            q.append(child)
            visits.add(child)


print("\n".join(map(str, PA_list[1:])))
