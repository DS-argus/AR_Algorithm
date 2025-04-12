import heapq
import sys
from collections import defaultdict, deque

input = sys.stdin.readline

T = int(input())
for t in range(T):

    N = int(input())
    parents = dict()

    for _ in range(N - 1):
        pa, ch = map(int, input().split())
        parents[ch] = pa

    A, B = map(int, input().split())

    Ancestors_A = []
    Ancestors_B = []

    anc = A
    Ancestors_A.append(anc)

    while anc in parents:
        anc = parents[anc]
        Ancestors_A.append(anc)

    anc = B
    if anc in Ancestors_A:
        print(anc)
        continue

    while anc in parents:
        anc = parents[anc]
        if anc in Ancestors_A:
            print(anc)
            break
