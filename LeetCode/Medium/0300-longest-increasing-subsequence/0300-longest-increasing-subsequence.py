class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        DP = [1]*len(nums)

        for i in range(1,len(nums)):
            
            for j in range(i):
                if nums[i] > nums[j]:
                    DP[i] = max(DP[i], DP[j] + 1)
        
        
        maxVal = 0
        for val in DP:
            maxVal = max(maxVal, val)

        return maxVal