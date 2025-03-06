import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

A, B = map(int, input().split())

cnt = 1

while B > A:
    if B % 2 == 0:
        B = B // 2
        cnt += 1

    else:
        if (B - 1) % 10 == 0:
            B = (B - 1) // 10
            cnt += 1
        else:
            print(-1)
            exit()


if B == A:
    print(cnt)
else:
    print(-1)
