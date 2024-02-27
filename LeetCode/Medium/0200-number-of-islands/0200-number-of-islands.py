class Solution:

    # index가 grid 범위에 있는지 체크하는 함수
    def isValid(self, r, c, i, j):
        return True if i >= 0 and i < r and j >= 0 and j < c else False

    # DFS 수행하는 함수 : 방문한 경우 "0"으로 값을 변경
    def DFS(self, grid, i, j):
        grid[i][j] = "0"
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        for direction in directions:
            new_i, new_j = i + direction[0], j + direction[1]

            if self.isValid(len(grid), len(grid[0]), new_i, new_j) and grid[new_i][new_j] == "1":
                self.DFS(grid, new_i, new_j)

    def numIslands(self, grid: List[List[str]]) -> int:
        result = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    result += 1
                    self.DFS(grid, i, j)
                    
        return result



