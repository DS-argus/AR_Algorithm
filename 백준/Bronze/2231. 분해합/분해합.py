import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N = int(input())


def get_sum_of_positions(n: int) -> int:

    s = 0
    while n >= 1:
        s += n % 10
        n = n // 10

    return s


for gen in range(1, N):
    if get_sum_of_positions(gen) + gen == N:
        print(gen)
        exit()

print(0)
