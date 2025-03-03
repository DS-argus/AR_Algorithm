import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())

numbers = list(map(int, input().split()))
numbers.sort()


def recursive(ans: list):
    if len(ans) == M:
        print(" ".join(map(str, ans)))
        return

    for number in numbers:
        if number not in ans:
            recursive(ans + [number])


for number in numbers:
    recursive([number])
