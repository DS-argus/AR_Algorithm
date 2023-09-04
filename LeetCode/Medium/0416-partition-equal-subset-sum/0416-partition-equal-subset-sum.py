class Solution:

    def canPartition(self, nums: List[int]) -> bool:
        
        # 만약 전체 sum이 홀수면 동일하게 나눠질 수 없음
        if sum(nums) % 2 != 0 : return False

        # 주어진 list에서 중복없이 조합해서 전체 sum의 절반을 만들 수 있니?
        targetSum = sum(nums) // 2

        # DP[i] = targetSum이 i+1일 때, i+1을 만들 수 있는지 여부
        # DP2[i] = i+1을 만들 수 있을 때, 앞으로 사용가능한 num list
        DP = [False] * targetSum
        DP2 = [[]] * targetSum
        
        # DP list 채우기
        for i in range(targetSum):

            # 만약 target과 동일한 값이 nums에 있으면 무조건 DP[i] = True이고 DP2[i]는 nums에서 i+1제거
            if (i+1) in nums:
                left = nums[:]
                left.remove(i+1)
                DP[i], DP2[i] = True, left
                continue
            
            # 만약 동일한 값이 아니라면 nums를 하나씩 돌면서 체크
            for num in nums:

                # i+1 - num에 해당하는 값을 만들어낼 수 있으면 가능성 있음
                if (i+1)-num >= 1 and DP[i-num] == True:
                    if num in DP2[i-num]:
                        left = DP2[i-num][:]
                        left.remove(num)
                        DP[i], DP2[i] = True, left
                        # break

        return DP[-1]




 

