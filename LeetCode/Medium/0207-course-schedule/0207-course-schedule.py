class Solution:
#     def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
#         # dfs
#         preMap = {i: [] for i in range(numCourses)}

#         # map each course to : prereq list
#         for crs, pre in prerequisites:
#             preMap[crs].append(pre)

#         visiting = set()

#         def dfs(crs):
#             if crs in visiting:
#                 return False
#             if preMap[crs] == []:
#                 return True

#             visiting.add(crs)
#             for pre in preMap[crs]:
#                 if not dfs(pre):
#                     return False
#             visiting.remove(crs)
#             preMap[crs] = []
#             return True

#         for c in range(numCourses):
#             if not dfs(c):
#                 return False
#         return True

    def DFS(self, node, visited, recursion_stack, adj_matrix):
        visited[node] = True
        recursion_stack[node] = True

        for neighbor in range(len(adj_matrix)):
            if adj_matrix[node][neighbor] == 1:
                if not visited[neighbor]:
                    if self.DFS(neighbor, visited, recursion_stack, adj_matrix):
                        return True
                elif recursion_stack[neighbor]:
                    return True

        recursion_stack[node] = False
        return False

    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adj_matrix = [[0 for _ in range(numCourses)] for _ in range(numCourses)]

        for pair in prerequisites:
            adj_matrix[pair[0]][pair[1]] = 1

        visited = [False] * numCourses
        recursion_stack = [False] * numCourses

        for i in range(numCourses):
            if not visited[i]:
                if self.DFS(i, visited, recursion_stack, adj_matrix):
                    return False

        return True