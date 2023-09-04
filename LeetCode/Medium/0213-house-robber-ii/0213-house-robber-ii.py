class Solution:

    # House Robber 1의 답
    # nums의 양끝이 연결되어 있지 않음
    def Rob_Helper(self, nums: List[int]) -> int:
        
        # DP list 정의 : DP[i] = nums[:i+1]에서 얻을 수 있는 maximum amount
        DP = [0] * len(nums)

        # i == 0 , i == 1인 경우는 따로. 점화식에 DP[i-2] 들어가서
        DP[0] = nums[0]
        DP[1] = max(nums[0], nums[1])

        # DP list 채우기
        for i in range(2, len(nums)):
            
            # 1. nums[i-1]을 선택한 경우 : DP[i-1]과 동일
            # 2. nums[i-1]을 선택하지 않은 경우 : DP[i-2] + nums[i] 
            DP[i] = max(nums[i] + DP[i-2], DP[i-1])

        # DP list 마지막 값 return
        return DP[-1]


    # House Robber 2
    def rob(self, nums: List[int]) -> int:
        # nums 개수가 1, 2, 3인 경우는 따로, 개수 4 이상부터 nums[2:-1] 가능
        if len(nums) == 1:
            return nums[0]

        elif len(nums) == 2:
            return max(nums[0], nums[1])

        else:
            # 1. 첫번째를 선택하지 않는 경우 : nums[1:]에서 max 찾기
            # 2. 첫번째를 선택하는 경우 : nums[2:-1]에서 max 찾기 + nums[0]
            return max(self.Rob_Helper(nums[1:]), \
                       self.Rob_Helper(nums[:-1]))

    