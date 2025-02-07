import sys

input = sys.stdin.readline

from collections import defaultdict, deque

N = int(input())
A, B = map(int, input().split())
M = int(input())

parents = defaultdict(list)

for _ in range(M):
    x, y = map(int, input().split())
    parents[y].append(x)


# A, B각각 parents를 따라서 올라가다가 처음 겹치는 사람찾아야함
def find_ancestors(parents, me):
    ancestor = [me]

    start = me

    while start in parents.keys():
        start = parents[start][0]
        ancestor.append(start)

    return ancestor


ancestor_A = find_ancestors(parents, A)
ancestor_B = find_ancestors(parents, B)


# 겹치는게 없으면 -1 출력
if not (set(ancestor_A) & set(ancestor_B)):
    print(-1)
    exit()


# 겹치는게 있으면
for i, ancA in enumerate(ancestor_A):
    for j, ancB in enumerate(ancestor_B):
        if ancA == ancB:
            print(i + j)
            exit()
