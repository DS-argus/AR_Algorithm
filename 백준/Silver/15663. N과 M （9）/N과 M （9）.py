import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, M = map(int, input().split())

numbers = list(map(int, input().split()))
numbers.sort()


def recursive(ans: list, left: list):
    if len(ans) == M:
        results.append(ans)
        return

    prev = -1
    for l in left:
        if l != prev:
            new_left = left[:]
            new_left.remove(l)

            recursive(ans + [l], new_left)
            prev = l


results = []

prev = -1
for idx in range(N):
    if prev != numbers[idx]:
        left = numbers[:]
        left.remove(numbers[idx])
        recursive([numbers[idx]], left)
        prev = numbers[idx]

for result in results:
    print(" ".join(map(str, result)))
