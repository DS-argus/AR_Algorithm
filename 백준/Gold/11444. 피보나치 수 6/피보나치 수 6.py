import sys

input = sys.stdin.readline

N = int(input())

memo = dict()
memo[0] = 0
memo[1] = 1
memo[2] = 1


def fib(n):
    if n in memo.keys():
        return memo[n]

    k = n // 2
    if n % 2 == 0:
        ans = fib(k) * fib(k + 1) + fib(k - 1) * fib(k)
    else:
        ans = fib(k + 1) ** 2 + fib(k) ** 2

    memo[n] = ans % 1_000_000_007
    return memo[n]


print(fib(N))
