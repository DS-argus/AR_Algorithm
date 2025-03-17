import sys
from collections import defaultdict, deque

input = sys.stdin.readline


# 1<=N<=1_000_000_000_000_000_000
N = int(input())

memo = dict()
memo[0] = 0
memo[1] = 1
memo[2] = 1


def fib(n):
    if n in memo.keys():
        return memo[n]

    if n % 2 == 0:
        # print(f"fib({n}) = fib({n//2})*fib({n//2+1}) + fib({n//2-1})*fib(n//2)")
        ans = fib(n // 2) * fib(n // 2 + 1) + fib(n // 2 - 1) * fib(n // 2)
    else:
        #print(f"fib({n}) = fib({n-n//2})*fib({n//2+1}) + fib({n-n//2-1})*fib({n//2})")
       
        ans = fib(n // 2 + 1) ** 2 + fib(n // 2) ** 2

    memo[n] = ans % 1_000_000
    return memo[n]


print(fib(N))
