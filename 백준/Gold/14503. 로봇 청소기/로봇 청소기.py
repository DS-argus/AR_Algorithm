N, M = map(int, input().split())
r, c, d = map(int, input().split())
space = [list(map(int, input().split())) for _ in range(N)]

move = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # 0, 1, 2, 3 : 북, 동, 남, 서
cnt = 0
stack = [(r, c, d)]

while stack:
    r, c, d = stack.pop()
    if not space[r][c]:
        space[r][c] = 2
        cnt += 1

    is_valid = False
    for i in range(4):
        dr, dc = move[d-i-1]
        nr, nc = r + dr, c + dc

        if 0 <= nr < N and 0 <= nc < M and (not space[nr][nc]):
            if not is_valid: stack.append((nr, nc, (d-i-1)%4))
            is_valid = True

    if not is_valid:
        dr, dc = move[(d-2)%4]
        nr, nc = r+dr, c+dc
        if nr < 0 or nr >= N or nc < 0 or nc >= M or space[nr][nc] == 1: 
            break
        else:
            stack.append((nr, nc, d))

print(cnt)