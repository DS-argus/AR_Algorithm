from collections import deque

def solution(maps):
    n, m = len(maps), len(maps[0])
    start = (0, 0)
    end = (n-1, m-1)
    
    def valid_moves(i, j):
        MOVES = [(1,0), (-1,0), (0,1), (0,-1)]
    
        for di, dj in MOVES:
            ni, nj = i + di, j + dj
            if 0<=ni<n and 0<=nj<m:
                yield (ni, nj)
    
    q = deque([(0, 0, 1)])
    visit = set()
    
    while q:
        i, j, count = q.popleft()
        
        if (i, j) in visit:
            continue
        
        if (i, j) == end:
            return count
        
        visit.add((i, j))
        
        for ni, nj in valid_moves(i, j):
            if maps[i][j] != 0:
                q.append((ni, nj, count + 1))
        
    return -1
    
    