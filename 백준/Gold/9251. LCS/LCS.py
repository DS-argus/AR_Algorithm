import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

s1 = input().rstrip()
s2 = input().rstrip()


dp = [[-1 for _ in range(len(s2))] for _ in range(len(s1))]

dp[-1][-1] = int(s1[-1] == s2[-1])

for i in range(len(s1) - 1, -1, -1):
    for j in range(len(s2) - 1, -1, -1):
        if i == len(s1) - 1 and j == len(s2) - 1:
            continue

        if s1[i] == s2[j]:
            if i == len(s1) - 1 or j == len(s2) - 1:
                dp[i][j] = 1

            else:
                dp[i][j] = dp[i + 1][j + 1] + 1

        else:
            if i == len(s1) - 1:
                dp[i][j] = dp[i][j + 1]
            elif j == len(s2) - 1:
                dp[i][j] = dp[i + 1][j]

            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])

print(dp[0][0])
