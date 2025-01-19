import sys

input = sys.stdin.readline
INT_MAX = sys.maxsize

n, k = map(int, input().split())  # 물건의 수 n, 배낭의 용량 k
items = []  # 물건의 (무게, 가치) 리스트

for _ in range(n):
    w, v = map(int, input().split())
    items.append((w, v))

# 1차원 DP 배열 초기화
dp = [0] * (k + 1)

# DP 계산
for w, v in items:
    for capacity in range(k, w - 1, -1):  # 뒤에서부터 계산
        dp[capacity] = max(dp[capacity], dp[capacity - w] + v)

# 결과 출력
print(dp[k])
