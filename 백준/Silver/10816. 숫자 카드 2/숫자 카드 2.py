import sys

input = sys.stdin.readline

from collections import Counter

N = int(input())
has = list(map(int, input().split()))
M = int(input())
targets = list(map(int, input().split()))


d = Counter(has)

result = [d[target] for target in targets]
print(*result)
