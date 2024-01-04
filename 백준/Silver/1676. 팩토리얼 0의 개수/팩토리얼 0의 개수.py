N  = int(input())

c1, c2 = 0, 0
result = 1
for i in range(1, N+1):
    n = i
    while True:
        if n % 2 == 0:
            c1 += 1
            n /= 2

        if n % 5 == 0:
            c2 += 1
            n /= 5
        else:
            break

print(min(c1, c2))