N = int(input())
T, P = [0]*N, [0]*N
for i in range(N):
    T[i], P[i] = map(int, input().split())

DP = [0] * (N+1)

def dfs(idx):
    if idx + T[idx] > N:
        DP[idx] = DP[idx+1]
    else:
        DP[idx] = max(DP[idx+1], DP[idx+T[idx]]+P[idx])

for i in range(N-1, -1, -1):
    
    dfs(i)
    
print(DP[0])