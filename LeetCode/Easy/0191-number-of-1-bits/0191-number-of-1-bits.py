class Solution:
    def hammingWeight(self, n: int) -> int:
        val = 0
        for i in range(32):
            if n & (1<<(i)): val += 1
        return val
        