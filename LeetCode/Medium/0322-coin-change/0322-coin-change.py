class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        ## amount : 0 ~ amount
        DP = [0] * (amount+1)

        for i in range(1, amount+1):
            if i in coins:
                DP[i] = 1
                continue
            
            minVal = 2**(32)
            for coin in coins:
                if (i - coin) >= 1 and DP[i - coin] > 0:
                    
                    minVal = min(minVal, DP[i-coin]+1)


            if minVal == 2**(32):
                DP[i] = -1
            else:
                DP[i] = minVal

        return DP[-1]
    
                    
            
            

            
