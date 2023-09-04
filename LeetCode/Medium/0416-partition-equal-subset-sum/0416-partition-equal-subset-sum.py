class Solution:

    def canPartition(self, nums: List[int]) -> bool:

        totalSum = sum(nums)

        if totalSum % 2 != 0 : return False

        targetSum = totalSum // 2

        DP = [False] * targetSum
        DP2 = [[]] * targetSum
        
        for i in range(targetSum):
            if (i+1) in nums:
                DP[i], DP2[i] = True, [i+1]
                continue
            
            for num in nums:
                if (i+1)-num >= 1 and DP[i-num] == True:
                    temp = nums[:]
                    for selected in DP2[i-num]:
                        temp.remove(selected)
                    
                    if num in temp:
                        DP[i] = True
                        # DP2[i] = DP2[i-num][:] 
                        # DP2[i].append(num)
                        DP2[i] = DP2[i-num] + [num]
                        break

        return DP[-1]




 

