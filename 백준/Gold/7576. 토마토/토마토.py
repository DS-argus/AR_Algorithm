from collections import deque

M, N = map(int, input().split())
box = [list(map(int, input().split())) for _ in range(N)]

# 이동 방향
move = [(1, 0), (0, 1), (-1, 0), (0, -1)]

# BFS 초기화를 위해 익은 토마토 큐에 추가
riped = deque()
for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            riped.append((i, j))

def bfs():
    while riped:
        cnt_x, cnt_y = riped.popleft()
        for dx, dy in move:
            nx, ny = cnt_x + dx, cnt_y + dy
            if 0 <= nx < N and 0 <= ny < M and box[nx][ny] == 0:
                box[nx][ny] = box[cnt_x][cnt_y] + 1
                riped.append((nx, ny))

bfs()

max_day = 0
flag = False
for i in range(N):
    for j in range(M):
        if box[i][j] == 0:
            flag = True
        max_day = max(max_day, box[i][j])

if flag:
    print(-1)
else:
    print(max_day - 1)