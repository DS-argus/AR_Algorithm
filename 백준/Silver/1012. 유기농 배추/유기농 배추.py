import sys

input = sys.stdin.readline
# input 받는 법 : sys.stdin.readline()

from collections import deque


def valid_moves(move: tuple[int, int], ROW: int, COL: int) -> list[tuple]:

    row, col = move

    MOVES = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    moves = []

    for d_row, d_col in MOVES:
        new_row, new_col = row + d_row, col + d_col
        if 0 <= new_row < ROW and 0 <= new_col < COL:
            moves.append((new_row, new_col))

    return moves


def find_island(locations: list, ROW: int, COL: int) -> int:
    q = deque()
    cnt = 0

    q.append(locations[0])
    island = []
    island.append(locations[0])
    while q:
        move = q.popleft()

        next_moves = valid_moves(move, ROW, COL)

        for next in next_moves:
            if next in locations and not next in island:
                q.append(next)
                island.append(next)

        if not q:
            cnt += 1

            for i in island:
                locations.remove(i)

            island = []

            if len(q) == 0 and locations:
                q.append(locations[0])
                island.append(locations[0])

    return cnt


T = int(input())
Ms, Ns, Ks, locations = [0] * T, [0] * T, [0] * T, [[0]] * T

for t in range(T):
    Ms[t], Ns[t], Ks[t] = map(int, input().split(" "))
    locations[t] = [tuple(map(int, input().split(" "))) for _ in range(Ks[t])]

for t in range(T):
    print(find_island(locations[t], Ms[t], Ns[t]))
