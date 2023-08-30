N = int(input())

DP = [[0 for _ in range(2)]for _ in range(N)]

for i in range(N):
    if i == 0:
        DP[i][1] = 1
    else:
        DP[i][0] = DP[i-1][0] + DP[i-1][1]
        DP[i][1] = DP[i-1][0]

print(DP[-1][0]+DP[-1][1])