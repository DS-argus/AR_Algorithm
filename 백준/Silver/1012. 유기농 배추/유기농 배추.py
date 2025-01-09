import sys
from collections import deque

input = sys.stdin.readline


def valid_moves(move, ROW, COL):
    row, col = move
    MOVES = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    for d_row, d_col in MOVES:
        new_row, new_col = row + d_row, col + d_col
        if 0 <= new_row < ROW and 0 <= new_col < COL:
            yield (new_row, new_col)


def find_island(locations, ROW, COL):
    locations = set(locations)  # Optimize lookups
    cnt = 0

    while locations:
        cnt += 1
        q = deque([locations.pop()])  # Start from any location

        while q:
            move = q.popleft()
            for next_move in valid_moves(move, ROW, COL):
                if next_move in locations:
                    locations.remove(next_move)
                    q.append(next_move)

    return cnt


# Input reading
T = int(input())
results = []

for _ in range(T):
    M, N, K = map(int, input().split())
    locations = [tuple(map(int, input().split())) for _ in range(K)]
    results.append(find_island(locations, M, N))

# Output results
for res in results:
    print(res)
