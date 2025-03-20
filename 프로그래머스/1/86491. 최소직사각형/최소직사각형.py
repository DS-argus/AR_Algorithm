def solution(sizes):
    X, Y = 0, 0
    for x, y in sizes:
        X = max(X, max(x, y))
        Y = max(Y, min(x, y))
        
    
    return X * Y