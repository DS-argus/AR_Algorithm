class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        DP = [[0 for _ in range(2)] for _ in range(len(cost))]

        for i in range(len(cost)):
            if i == 0:
                DP[i][0] = 0
                DP[i][1] = cost[i]
            else:
                DP[i][0] = DP[i-1][1]
                DP[i][1] = min(DP[i-1][1]+cost[i], DP[i-1][0]+cost[i])
        
        print(DP)
        return min(DP[-1][0], DP[-1][1])