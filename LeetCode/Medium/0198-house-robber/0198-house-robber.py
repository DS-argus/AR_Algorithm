class Solution:

    def rob(self, nums: List[int]) -> int:
        DP = [0] * len(nums)

        for i in range(1, len(nums)+1):
            subList = nums[:i]
            
            if len(subList) == 1:
                DP[i-1] = nums[i-1]
                continue
            elif len(subList) == 2:
                DP[i-1] = max(subList[0], subList[1])
                continue
            
            DP[i-1] = max(nums[i-1] + DP[i-3], DP[i-2])


        return DP[-1]
