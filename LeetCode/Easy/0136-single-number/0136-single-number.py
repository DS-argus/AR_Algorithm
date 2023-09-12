class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bits = 0
        for num in nums:
            bits ^= 2 ** (num+3*10**4)
        
        return len(bin(bits))-30003
