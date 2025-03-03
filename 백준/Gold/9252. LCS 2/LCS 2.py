import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

s1 = input().rstrip()
s2 = input().rstrip()

l1, l2 = len(s1), len(s2)

dp = [[0 for _ in range(l2 + 1)] for _ in range(l1 + 1)]
dpstr = [["" for _ in range(l2 + 1)] for _ in range(l1 + 1)]

for i in range(l1 - 1, -1, -1):
    for j in range(l2 - 1, -1, -1):
        if s1[i] == s2[j]:
            dp[i][j] = dp[i + 1][j + 1] + 1
            dpstr[i][j] = s1[i] + dpstr[i + 1][j + 1]

        else:
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
            dpstr[i][j] = (
                dpstr[i + 1][j]
                if len(dpstr[i + 1][j]) > len(dpstr[i][j + 1])
                else dpstr[i][j + 1]
            )

print(dp[0][0])
print(dpstr[0][0])
