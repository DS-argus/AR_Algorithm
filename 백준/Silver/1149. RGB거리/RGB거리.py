import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())
COST = [list(map(int, input().split())) for _ in range(N)]

dp = [[0, 0, 0] for _ in range(N)]

dp[0][0] = COST[0][0]
dp[0][1] = COST[0][1]
dp[0][2] = COST[0][2]

for i in range(1, N):
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + COST[i][0]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + COST[i][1]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + COST[i][2]

print(min(dp[-1]))
