n = int(input())
M = int(input())
L = list(map(int, input().split()))

L.sort()

l, r = 0, n-1
count = 0
while l<r:
    if L[l]+L[r] == M:
        count += 1
        l += 1
        r -= 1
    elif L[l]+L[r] < M:
        l += 1
    else:
        r -= 1
        
print(count)