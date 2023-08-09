n = int(input())

l,r = 0, n

count = 0

for i in range(1,n+1):
    if i%2 == 0 and int((n+i//2)/i) == (n+i//2)/i and (n+i//2)/i - i/2 >= 1 :
        count += 1
    elif i%2 != 0 and int(n/i) == n/i and n/i - i//2 >= 1 :
        count += 1
   
print(count)
        