import sys
from typing import Iterator

input = sys.stdin.readline

N, M = map(int, input().split())

from collections import deque


def valid_moves(n: int, m: int) -> Iterator[tuple]:
    MOVE = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    for dn, dm in MOVE:
        if 0 <= n + dn < N and 0 <= m + dm < M:
            yield (n + dn, m + dm)


islands = [list(map(int, input().split())) for _ in range(N)]
distances = [[0 for _ in range(M)] for _ in range(N)]
visits = set()
target_n, target_m = 0, 0
flag = False
for n in range(N):
    for m in range(M):
        if islands[n][m] == 2:
            target_n, target_m = n, m
            flag = True
            break
    if flag:
        break

q = deque()
q.append((target_n, target_m, 0))
visits.add((target_n, target_m))
while q:
    cnt_n, cnt_m, dist = q.popleft()
    distances[cnt_n][cnt_m] = dist

    for next_n, next_m in valid_moves(cnt_n, cnt_m):
        if islands[next_n][next_m] != 0 and not (next_n, next_m) in visits:
            q.append((next_n, next_m, dist + 1))
            visits.add((next_n, next_m))

for n in range(N):
    for m in range(M):
        island = islands[n][m]
        distance = distances[n][m]
        if island == 1 and distance == 0:
            distances[n][m] = -1


for n in range(N):
    print(*distances[n])
