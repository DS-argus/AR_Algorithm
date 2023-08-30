class Solution:
    def climbStairs(self, n: int) -> int:
        DP = [0]*n

        for i in range(n):
            if i == 0: DP[i] = 1
            elif i == 1 : DP[i] = 2
            else:
                DP[i] = DP[i-1] + DP[i-2]
        
        return DP[-1]