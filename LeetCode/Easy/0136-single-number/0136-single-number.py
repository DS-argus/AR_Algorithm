class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        minVal = 3*10**4
        for num in nums:
            minVal = min(minVal, num)

        bits = 0
        for num in nums:
            bits ^= 2 ** (num-minVal)

        return len(bin(bits))-3+minVal
