import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())


def recursive(ans: list):
    if len(ans) == M:
        print(" ".join(map(str, ans)))
        return
    last = ans[-1]
    for i in range(last + 1, N + 1):
        recursive(ans + [i])


for i in range(1, N + 1):
    recursive([i])
