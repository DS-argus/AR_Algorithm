import sys
from collections import defaultdict, deque

sys.setrecursionlimit(1000000)
input = sys.stdin.readline


V = int(input())

# EDGES = defaultdict(dict)
# for _ in range(V):
#     info = list(map(int, input().split()))
#
#     V = info[0]
#     num_edges = (len(info) - 2) // 2
#
#     for i in range(num_edges):
#         v, w = info[1:][2 * i], info[1:][2 * i + 1]
#         EDGES[V][v] = w

EDGES = defaultdict(dict)
for _ in range(V - 1):
    v, a, w = map(int, input().split())
    EDGES[v][a] = w
    EDGES[a][v] = w

max_diameter = 0


def dfs(start, visit, dist, dist_list):

    visit.add(start)
    dist_list.append((dist, start))

    max_dist = 0
    for neighbor, weight in EDGES[start].items():
        if neighbor not in visit:
            dfs(neighbor, visit, dist + weight, dist_list)

    return max_dist


# vertex 1에서 가장 거리가 먼 vertex
visit = set()
dist_list = []
dist = 0
dfs(1, visit, dist, dist_list)

dist_list.sort(key=lambda x: x[0], reverse=True)
farthest_dist, farthest_node = dist_list[0][0], dist_list[0][1]

# farthest node에서 가장 거리가 먼 vertex
visit = set()
dist_list = []
dist = 0
dfs(farthest_node, visit, dist, dist_list)
dist_list.sort(key=lambda x: x[0], reverse=True)
print(dist_list[0][0])
