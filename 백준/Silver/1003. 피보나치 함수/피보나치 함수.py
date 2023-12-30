N = int(input())

for _ in range(N):
    num = int(input())
    DP = [[0, 0] for _ in range(num+1)]

    if num == 0:
        print(1, 0)
    elif num == 1:
        print(0, 1)
    elif num == 2:
        print(1, 1)
    else:
        DP[0] = [1,0]
        DP[1] = [0,1]
        DP[2] = [1,1]
        for i in range(3, num+1):
            DP[i][0] = DP[i-2][0] + DP[i-1][0]
            DP[i][1] = DP[i-2][1] + DP[i-1][1]
        print(DP[num][0], DP[num][1])