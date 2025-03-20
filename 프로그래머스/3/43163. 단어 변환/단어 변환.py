from collections import defaultdict, deque
def solution(begin, target, words):
    
    # 바로 불가능한 케이스
    if target not in words:
        return 0
    
    # 글자가 한개만 다른지 판단해서 이동가능한지 return하는 함수
    def isMovable(A: str, B: str)->bool:
        if len(A) != len(B):
            return False
        
        N = len(A)
        cnt = 0
        for i in range(N):
            if A[i] != B[i]:
                cnt += 1
            
            if cnt > 1:
                return False
        
        return True
    
    # hit + words 를 이용한 adjmatrix 생성
    EDGES = defaultdict(list)
    nodes = words +[begin]
    for A in nodes:
        for B in nodes:
            if A == B:
                continue
            
            if isMovable(A, B):
                EDGES[A].append(B)
                EDGES[B].append(A)
    
    # bfs 수행
    q = deque([(begin, 0)])
    
    visit = set()
    
    while q:
        word, count = q.popleft()
        
        if word in visit:
            continue
        
        if word == target:
            return count
        
        visit.add(word)
        
        for neighbor in EDGES[word]:
            q.append((neighbor, count+1))
    
    return 0