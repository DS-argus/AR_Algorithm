import sys

# input 받는 법 : sys.stdin.readline()

ans_W = [
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
]

ans_B = [
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
]


def compare_strs(test: str, answer: str) -> int:
    assert len(test) == len(answer)

    diff_cnt = 0
    for i in range(len(test)):
        diff_cnt += test[i] != answer[i]

    return diff_cnt


def check_BOARD(board: list, row: int, col: int, start: str = "W") -> int:
    if start == "W":
        answer = ans_W
    else:
        answer = ans_B

    cnt = 0
    for i in range(8):
        cnt += compare_strs(board[row + i][col : col + 8], answer[i])

    return cnt


N, M = map(int, sys.stdin.readline().split())
BOARD = [sys.stdin.readline().split()[0] for _ in range(N)]

modifications = []
for i in range(N - 8 + 1):
    for j in range(M - 8 + 1):
        start_row, start_col = i, j
        min_W = check_BOARD(BOARD, start_row, start_col, "W")
        min_B = check_BOARD(BOARD, start_row, start_col, "B")
        modifications.append(min(min_W, min_B))

print(min(modifications))
