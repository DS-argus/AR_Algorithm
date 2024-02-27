class Solution:

    # index가 grid 범위에 있는지 체크하는 함수
    def isValid(self, r, c, i, j):
        return 0 <= i < r and 0 <= j < c

    def BFS(self, grid, d_matrix, i, j):
        directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        depth = 0
        visited = []

        q = deque()
        q.append((i, j, depth))

        while q:
            
            cur_i, cur_j, cur_depth = q.popleft()
            grid[cur_i][cur_j] = 2
            d_matrix[cur_i][cur_j] = min(d_matrix[cur_i][cur_j], cur_depth)
            
            for direction in directions:
                new_i, new_j = cur_i + direction[0], cur_j + direction[1]

                if self.isValid(len(grid), len(grid[0]), new_i, new_j) and grid[new_i][new_j] == 1:
                    q.append((new_i, new_j, cur_depth+1))
                    visited.append((new_i, new_j))
        
        # 다시 방문한것 되돌려 놓기
        for visit in visited:
            grid[visit[0]][visit[1]] = 1
        
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        d_matrix = [[100 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 2 : 
                    self.BFS(grid, d_matrix, i, j)
        
        result = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1 and d_matrix[i][j] == 100:
                    return -1

                if d_matrix[i][j] != 100:
                    result = max(result, d_matrix[i][j])
        
        return result
        