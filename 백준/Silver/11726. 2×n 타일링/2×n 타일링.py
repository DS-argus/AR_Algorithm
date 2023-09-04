n = int(input())
DP = [0]*n

for i in range(n):
    if i == 0:
        DP[i] = 1
        continue
       
    if i == 1:
        DP[i] = 2
        continue
        
    DP[i] = DP[i-1] + DP[i-2]

print(DP[-1] % 10007)