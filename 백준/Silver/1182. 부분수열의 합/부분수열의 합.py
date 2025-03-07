import sys
from collections import deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, S = map(int, input().split())
numbers = list(map(int, input().split()))

cnt = [0]


def recursive(i: int, s: int):
    if i == N:
        if s == S:
            cnt[0] += 1
        return

    recursive(i + 1, s + numbers[i])  # numbers[i] 포함
    recursive(i + 1, s)  # numbers[i] 미포함

    return


recursive(0, 0)

if S == 0:
    print(cnt[0] - 1)
else:
    print(cnt[0])
