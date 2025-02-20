import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline


N, M = map(int, input().split())
cards = list(map(int, input().split()))

cards.sort()
min_val = sys.maxsize
results = []
for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            score = cards[i] + cards[j] + cards[k]

            if score <= M:
                min_val = min(min_val, M - score)

print(M - min_val)
