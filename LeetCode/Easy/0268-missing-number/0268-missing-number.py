class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        bits = (1<<(len(nums)+1))-1

        for num in nums:
            bits -= (1<<num)
        
        i= 0
        while bits % 2 != 1:
            bits >>= 1
            i+=1
        
        return i
            
            
        