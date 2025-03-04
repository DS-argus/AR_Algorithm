import string
import sys
from bisect import bisect_left
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())
hash = [0] * 10_001

for _ in range(N):
    num = int(input())
    hash[num] += 1


for idx, n in enumerate(hash):

    while n:
        print(idx)
        n -= 1
