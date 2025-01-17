import sys

input = sys.stdin.readline

M, N, K = map(int, input().split())
container = [[list(map(int, input().split())) for _ in range(N)] for _ in range(K)]

from collections import deque


def valid_moves(k, n, m):
    MOVE = [(0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0), (1, 0, 0), (-1, 0, 0)]

    for dk, dn, dm in MOVE:
        new_k, new_n, new_m = k + dk, n + dn, m + dm

        if 0 <= new_k < K and 0 <= new_n < N and 0 <= new_m < M:
            yield (new_k, new_n, new_m)


distance = [[[-1 for _ in range(M)] for _ in range(N)] for _ in range(K)]

no_tomato = 0
visits = set()
q = deque()
for k in range(K):
    for n in range(N):
        for m in range(M):
            if container[k][n][m] == 1:
                visits.add((k, n, m))
                q.append((k, n, m, 0))
            elif container[k][n][m] == -1:
                no_tomato += 1


while q:
    cnt_k, cnt_n, cnt_m, dist = q.popleft()
    # distance[cnt_k][cnt_n][cnt_m] = min(dist, distance[cnt_k][cnt_n][cnt_m])
    distance[cnt_k][cnt_n][cnt_m] = dist

    for next_k, next_n, next_m in valid_moves(cnt_k, cnt_n, cnt_m):
        if (
            not (next_k, next_n, next_m) in visits
            and container[next_k][next_n][next_m] != -1
        ):
            q.append((next_k, next_n, next_m, dist + 1))
            visits.add((next_k, next_n, next_m))


max_date = 0
for k in range(K):
    for n in range(N):
        for m in range(M):
            dist = distance[k][n][m]
            original = container[k][n][m]

            if original != -1 and dist == -1:
                print(-1)
                exit()

            max_date = max(max_date, distance[k][n][m])

print(max_date)
