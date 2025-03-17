import sys
from collections import defaultdict, deque

input = sys.stdin.readline


# 1<=N<=1_000_000_000_000_000_000
N = int(input())

P = 15 * 10**5

N %= P

x, y = 0, 1

for _ in range(2, N + 1):
    y, x = (y + x) % 1_000_000, y

print(y)
