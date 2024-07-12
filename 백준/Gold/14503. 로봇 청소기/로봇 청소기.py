N, M = map(int, input().split())
r, c, d = map(int, input().split())
space = [list(map(int, input().split())) for _ in range(N)]

move = [(-1, 0), (0, 1), (1, 0), (0, -1)]  # 0, 1, 2, 3 : 북, 동, 남, 서
cnt = 0
stack = [(r, c, d)]
while stack:
    flag = False
    r, c, d = stack.pop()
    if not space[r][c]:
        space[r][c] = 2
        cnt += 1

    valid_moves = []
    for i in range(4):
        dr, dc = move[d-i-1]
        nr, nc = r + dr, c + dc

        if 0 <= nr < N and 0 <= nc < M and (not space[nr][nc]): valid_moves.append((nr, nc, (d-i-1)%4))

    if not valid_moves:
        # breakpoint()
        dr, dc = move[(d-2)%4]
        nr, nc = r+dr, c+dc
        if nr < 0 or nr >= N or nc < 0 or nc >= M or space[nr][nc] == 1:  
            break
        else:
            stack.append((nr, nc, d))

    else:
        stack.append(valid_moves[0])


# for i in range(N):
#     print(space[i])

print(cnt)