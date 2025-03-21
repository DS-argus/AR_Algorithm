def solution(numbers):
    
    answers = []
    
    def isPrime(n: int):
        if n == 1 or n == 0:
            return False
        prime = True
        for i in range(2, int(n**(0.5))+1):
            if n % i == 0:
                prime = False
                break
        
        return prime
                       
    
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