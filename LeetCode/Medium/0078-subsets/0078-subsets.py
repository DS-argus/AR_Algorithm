class Solution:
    def __subsetsHelp(self, nums: list[int], result: list[list[int]]) -> None:
        if len(nums)==0:
            return
        
        if nums not in result:
            result.append(nums)
                    
        for num in nums:
            nextNums = nums.copy()
            nextNums.remove(num)
            self.__subsetsHelp(nextNums, result)

    def subsets(self, nums: list[int]) -> list[list[int]]:
        result = [[]]
        self.__subsetsHelp(nums, result)
        return result