import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())
numbers = list(map(int, input().split()))

dp = [1] * N

for i in range(1, N):
    largest = 0
    # 이전까지 numbers[i] 보다 작은 숫자 중 dp값 가장 큰 것
    for j in range(i):
        if numbers[i] > numbers[j]:
            largest = max(largest, dp[j])

    dp[i] = largest + 1
print(max(dp))
