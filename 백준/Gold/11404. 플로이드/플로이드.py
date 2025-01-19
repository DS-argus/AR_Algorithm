import sys

input = sys.stdin.readline
INT_MAX = sys.maxsize

n = int(input())
m = int(input())

edges_dict = {}
for _ in range(m):
    a, b, c = map(int, input().split())
    if (a, b) in edges_dict:
        edges_dict[(a, b)] = min(edges_dict[(a, b)], c)
    else:
        edges_dict[(a, b)] = c

distances = [[INT_MAX for _ in range(n)] for _ in range(n)]
for i in range(n):
    distances[i][i] = 0

for (start, end), time in edges_dict.items():
    distances[start - 1][end - 1] = time

for mid in range(n):
    for start in range(n):
        for end in range(n):

            distances[start][end] = min(
                distances[start][end],
                distances[start][mid] + distances[mid][end],
            )

for i in range(n):
    for j in range(n):
        if distances[i][j] == INT_MAX:
            distances[i][j] = 0

for row in distances:
    print(*row)
