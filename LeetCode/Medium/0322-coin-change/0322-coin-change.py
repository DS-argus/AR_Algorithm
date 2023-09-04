class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        # DP list 정의 : DP[i] = 금액이 i일 때 최소 coin 개수
        # min을 찾아야하니 나올 수 있는 가장 큰 값으로 초기화
        DP = [amount+1] * (amount+1)
        DP[0] = 0

        # i = 1부터 DP list 채우기(amount 0일 때는 0)
        for i in range(1, amount+1):

            # amount == coin이면 무조건 1
            if i in coins:
                DP[i] = 1
                continue
            
            # amount에서 coin을 뺐을 때 0보다 크면 min으로 업데이트
            for coin in coins:
                if (i - coin) >= 1:
                    DP[i] = min(DP[i], DP[i-coin]+1)
        

        return DP[-1] if DP[-1] != (amount+1) else -1

                    
            
            

            
