N = int(input())

DP = [0] * N

for i in range(N):
    if i == 0 or i == 1:
        DP[i] = 1
    else:
        DP[i] = DP[i-2] + DP[i-1]

print(DP[-1])