def answer(num):
    DP = [0 for _ in range(11)]
    DP[0] = 1
    DP[1] = 2
    DP[2] = 4

    if num <= 3:
        return (DP[num-1])
    else:
        for i in range(3, num):
            DP[i] = DP[i-3] + DP[i-2] + DP[i-1]
        return (DP[num-1])

n = int(input())


for _ in range(n):
    num  = int(input())
    print(answer(num))
