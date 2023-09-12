class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        minVal = min(nums)
        
        bits = 0
        for num in nums:
            bits ^= (1<<(num-minVal))

        return len(bin(bits))-3+minVal
