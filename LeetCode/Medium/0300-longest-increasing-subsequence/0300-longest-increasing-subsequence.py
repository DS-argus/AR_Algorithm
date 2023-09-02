class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # DP list 정의 
        # DP[i] = nums[:i+1]에서 nums[i]의 IS 순서
        DP = [1]*len(nums)

        # DP list 채우기(DP[0]은 1이니 생략)
        for i in range(1,len(nums)):

            # 0부터 i까지 확인 
            # nums[i]보다 작은 nums[j]의 경우 DP[j] + 1로 업데이트
            for j in range(i):
                if nums[i] > nums[j]:
                    DP[i] = max(DP[i], DP[j] + 1)
        
        # DP list내에서 최대값 return
        # 꼭 nums[i]에서 max가 나오는 것이 아님
        return max(DP)