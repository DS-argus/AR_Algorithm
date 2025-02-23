import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n, m = map(int, input().split())

SET = list(range(n + 1))


def find(x):
    if SET[x] != x:
        SET[x] = find(SET[x])
    return SET[x]


def union(a, b):
    root_a = find(a)
    root_b = find(b)

    if root_a != root_b:
        SET[root_b] = root_a


for _ in range(m):
    operation, a, b = map(int, input().split())

    if operation == 0:
        union(a, b)

    else:
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")
