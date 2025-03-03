import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())

numbers = sorted(list(map(int, input().split())))


def recursive(ans: list):
    if len(ans) == M:
        print(" ".join(map(str, ans)))
        return

    prev = -1
    for idx in range(N):
        if prev != numbers[idx]:
            recursive(ans + [numbers[idx]])
            prev = numbers[idx]


prev = -1
for idx in range(N):
    if prev != numbers[idx]:
        recursive([numbers[idx]])
        prev = numbers[idx]
