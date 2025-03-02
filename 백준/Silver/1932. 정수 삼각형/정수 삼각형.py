import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())

numbers = [list(map(int, input().split())) for _ in range(N)]

dp = [[0] * n for n in range(1, N + 1)]


dp[0][0] = numbers[0][0]

for i in range(1, N):

    for j in range(i + 1):
        if j == 0:
            dp[i][j] = dp[i - 1][j] + numbers[i][j]

        elif j == i:
            dp[i][j] = dp[i - 1][j - 1] + numbers[i][j]

        else:
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + numbers[i][j]


print(max(dp[-1]))
