import heapq as hq
import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

A, B, C = map(int, input().split())


def divide(A, B, C):
    if B == 1:
        return A % C

    half = divide(A, B // 2, C)
    ans = (half * half) % C

    if B % 2 == 1:
        ans *= A
        ans %= C

    return ans


print(divide(A, B, C))
