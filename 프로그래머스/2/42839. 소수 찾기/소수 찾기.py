def solution(numbers):
    
    answers = []
    
    def isPrime(n: int) -> bool:
        if n < 2:  
            return False

        for i in range(2, n):
            if n % i == 0:
                return False 

        return True
                       
    
    def recursive(string: str, left: str):
        if not left:
            return 
        
        for i in range(len(left)):
            nxt = string + left[i]
            
            if isPrime(int(nxt)):
                answers.append(int(nxt))
                
            recursive(nxt, left[:i] + left[i+1:])
            
    
    recursive("", numbers)

    return len(set(answers))