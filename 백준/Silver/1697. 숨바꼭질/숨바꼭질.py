import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline

N, K = map(int, input().split())

if N == K:
    print(0)
    exit()

q = deque([(N, 0)])
visit = set([N])
operator = "x"

while q:
    loc, time = q.popleft()

    if operator == "+":
        neighbors = [loc + 1, 2 * loc]
    elif operator == "-":
        neighbors = [loc - 1, 2 * loc]
    else:
        neighbors = [loc - 1, loc + 1, 2 * loc]

    for neighbor in neighbors:
        if neighbor == K:
            print(time + 1)
            exit()

        if 0 <= neighbor <= 100_000 and neighbor not in visit:
            visit.add(neighbor)
            q.append((neighbor, time + 1))
