class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        bits = 0
        for i in range(len(nums)):
            bits ^= 2 ** (nums[i]+3*10**4)
        
        return len(bin(bits))-30003
