n = int(input())
L = list(map(int, input().split()))

L.sort()

count = 0

for i in range(n):
    target = L[i]
    
    l, r = 0, n-1
    if l == i:
        l += 1

    if r == i:
        r -= 1
    while l<r:
        if L[l]+L[r] == target:
            count += 1
            break;
        elif L[l]+L[r] < target:
            l += 1
            if l == i:
                l += 1

        else:
            r -= 1
            if r == i:
                r -= 1

            
print(count)