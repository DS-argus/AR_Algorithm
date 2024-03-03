class Solution:
    def makeBase(self, n:int, base:int):
        result = ""

        while n >= base:
            result = str(n % base) + result
            
            n = n // base
        
        result = str(n) + result

        return result

    def isPalindrome(self, s) -> bool:
        """
        주어진 문자열 혹은 int가 Palindrome인가?
        """

        if isinstance(s, str):
            return s == s[::-1]
        
        elif isinstance(s, int):
            reverse = 0
            temp = s 
            while (temp != 0): 
                reverse = (reverse * 10) + (temp % 10) 
                temp = temp // 10
            
        return (reverse == s) # if it is true then it will return 1; 
    
    def isStrictlyPalindromic(self, n: int) -> bool:
        for i in range(2, n-1):
            num = self.makeBase(n, i)
            if not self.isPalindrome(num): return False
        return True
