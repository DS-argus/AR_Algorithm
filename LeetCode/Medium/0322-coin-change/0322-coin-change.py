class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        # DP list 정의
        # DP[i] = 금액이 i일 때 최소 coin 개수
        DP = [0] * (amount+1)

        # i = 1부터 DP list 채우기(amount 0일 때는 0)
        for i in range(1, amount+1):

            # amount == coin이면 무조건 1
            if i in coins:
                DP[i] = 1
                continue
            
            # coin의 최대값이 2**31-1, DP list의 최대값도 동일.
            # 따라서 min했을 때 valid한 값이면 작아질 수 있도록 더 크게 설정
            minVal = 2**(31)
            
            # amount에서 coin을 뺐을 때, DP list에 저장된 값 있으면 그 값에 +1
            # 모든 coin에 대해 확인해서 최솟값을 minVal에 저장
            for coin in coins:
                if (i - coin) >= 1 and DP[i - coin] > 0:
                    minVal = min(minVal, DP[i-coin]+1)


            # 만약 minVal이 그대로면, DP list에 없었다는 소리 -> -1 
            if minVal == 2**(31):
                DP[i] = -1

            # minVal이 바뀌었으면 DP[i] = minVal
            else:
                DP[i] = minVal

        # 마지막 값 return
        return DP[-1]
    
                    
            
            

            
