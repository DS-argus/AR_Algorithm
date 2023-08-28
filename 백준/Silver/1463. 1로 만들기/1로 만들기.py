n = int(input())
memo = [0] * n

for i in range(1, n):
    memo[i] = memo[i - 1] + 1
    
    if (i + 1) % 3 == 0:
        memo[i] = min(memo[i], memo[(i + 1) // 3 - 1] + 1)
    if (i + 1) % 2 == 0:
        memo[i] = min(memo[i], memo[(i + 1) // 2 - 1] + 1)

print(memo[-1])
