class Solution:

    def rob(self, nums: List[int]) -> int:
        # DP list 정의
        # DP[i] = nums[:i+1]에서 얻을 수 있는 maximum amount
        DP = [0] * len(nums)

        # DP list 채우기
        for i in range(len(nums)):
            
            # i == 0 , i == 1인 경우는 따로. 점화식에 DP[i-2] 들어가서
            # DP[0] = nums[0]
            if i == 0:
                DP[i] = nums[i]
                continue

            # DP[1] = nums[0], nums[1] 중 더 큰 값
            if i == 1:
                DP[i] = max(nums[0], nums[1])
                continue
            
            # 1. nums[i-1]을 선택한 경우 : DP[i-1]과 동일
            # 2. nums[i-1]을 선택하지 않은 경우 : DP[i-2] + nums[i] 
            DP[i] = max(nums[i] + DP[i-2], DP[i-1])

        # DP list 마지막 값 return
        return DP[-1]
