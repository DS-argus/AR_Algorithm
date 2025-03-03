import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())

numbers = list(map(int, input().split()))
numbers.sort()


def recursive(ans: list, idx: int):
    if len(ans) == M:
        print(" ".join(map(str, ans)))
        return

    for i in range(idx, N):
        recursive(ans + [numbers[i]], i)


for idx in range(N):
    recursive([numbers[idx]], idx)
