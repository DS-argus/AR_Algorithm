class Solution:
    def reverseBits(self, n: int) -> int:
        reversedBits = 0
        for i in range(32):
            reversedBits += (1<<(31-i))*((n>>i)%2)
        return reversedBits