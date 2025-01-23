import sys

input = sys.stdin.readline

from collections import defaultdict, deque

N, K = map(int, input().split())


def facto(n):
    DP = [1] * (n + 1)

    for i in range(1, n + 1):
        DP[i] = i * DP[i - 1]

    return DP[-1]


print(int(facto(N) / (facto(N - K) * facto(K))))
