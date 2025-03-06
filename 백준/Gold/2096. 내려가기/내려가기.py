import sys

sys.setrecursionlimit(1000000)
input = sys.stdin.readline


N = int(input())

dp = [0] * 3

dp2 = [0] * 3

for i in range(N):
    a, b, c = map(int, input().split())

    ba, bb, bc = dp

    dp[0] = max(ba, bb) + a
    dp[1] = max(ba, bb, bc) + b
    dp[2] = max(bb, bc) + c

    bba, bbb, bbc = dp2

    dp2[0] = min(bba, bbb) + a
    dp2[1] = min(bba, bbb, bbc) + b
    dp2[2] = min(bbb, bbc) + c


print(max(dp), min(dp2))
