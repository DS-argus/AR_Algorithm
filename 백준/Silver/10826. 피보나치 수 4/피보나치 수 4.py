import sys
from collections import defaultdict, deque

input = sys.stdin.readline
INT_MAX = sys.maxsize

N = int(input())
if N == 0:
    print(0)
    exit()
    
x, y = 0, 1

for _ in range(2, N + 1):
    y, x = y + x, y


print(y)
