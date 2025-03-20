from collections import deque

def solution(numbers, target):
    N = len(numbers)
    maxList = [sum(numbers[i:]) for i in range(N)]
    
    stack = [(0, 0)]
    ans = 0
    while stack:
        currentSum, idx = stack.pop()
        
        if idx == N: 
            if currentSum == target:
            	ans += 1 
            continue
        
        if -maxList[idx] <= target - currentSum <= maxList[idx]:
            stack.append((currentSum + numbers[idx], idx+1))
            stack.append((currentSum - numbers[idx], idx+1))

    return ans

        
        
    
    

        
    
    
    
	
    
    
    return 