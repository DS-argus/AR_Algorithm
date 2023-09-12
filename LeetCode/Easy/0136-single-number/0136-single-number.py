class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        bits = 0
        
        for num in nums:
            bits ^= 2 ** (num-min(nums))

        return len(bin(bits))-3+min(nums)
