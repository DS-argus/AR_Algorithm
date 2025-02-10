import sys
from collections import defaultdict, deque

input = sys.stdin.readline

N, M = map(int, input().split())

direct_boss = dict(zip(range(1, N + 1), list(map(int, input().split()))))

praises = defaultdict(int)
for _ in range(M):
    employer, praise = map(int, input().split())
    praises[employer] += praise

DP = [0] * N

for employer in range(2, N + 1):
    boss = direct_boss[employer]
    if employer in praises:
        DP[employer - 1] = DP[boss - 1] + praises[employer]
    else:
        DP[employer - 1] = DP[boss - 1]


print(*DP)
