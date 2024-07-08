import sys
from collections import deque

input = sys.stdin.read

# 전체 입력을 한 번에 읽어오고, 공백 기준으로 분할
data = input().split()

# 첫 두 값을 M과 N으로 설정
M = int(data[0])
N = int(data[1])

# 남은 데이터를 처리하여 box 리스트를 생성
box = []
index = 2
for _ in range(N):
    row = list(map(int, data[index:index + M]))
    box.append(row)
    index += M

# BFS 탐색을 위한 deque 초기화
queue = deque()
schedule = [[-1] * M for _ in range(N)]
move = [(0, 1), (0, -1), (-1, 0), (1, 0)]

# 처음부터 익은 토마토 위치를 모두 큐에 넣고, 해당 위치의 일수를 0으로 설정
for i in range(N):
    for j in range(M):
        if box[i][j] == 1:
            queue.append((i, j))
            schedule[i][j] = 0

# BFS 실행
while queue:
    x, y = queue.popleft()
    for dx, dy in move:
        nx, ny = x + dx, y + dy
        if 0 <= nx < N and 0 <= ny < M and box[nx][ny] == 0 and schedule[nx][ny] == -1:
            schedule[nx][ny] = schedule[x][y] + 1
            queue.append((nx, ny))

# 최종 결과 계산
max_days = 0
all_riped = True
for i in range(N):
    for j in range(M):
        if box[i][j] == 0:
            if schedule[i][j] == -1:
                all_riped = False
            else:
                max_days = max(max_days, schedule[i][j])

if all_riped:
    print(max_days)
else:
    print(-1)