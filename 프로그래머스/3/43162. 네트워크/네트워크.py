def solution(n, computers):
    adjMatrix = computers
    visit = [False] * n
    ans = 0
    for V in range(n):
        if visit[V]:
            continue
            
        stack = [V]
        
        while stack:
            currentNode = stack.pop()
            
            if visit[currentNode]:
                continue
            
            visit[currentNode] = True
            
            for idx, isConnected in enumerate(adjMatrix[currentNode]):
                if idx != currentNode and isConnected:
                    stack.append(idx)

        ans += 1
        
    return ans
        
        