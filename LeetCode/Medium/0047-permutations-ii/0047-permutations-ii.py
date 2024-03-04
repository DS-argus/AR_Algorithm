class Solution:
    def permutation(self, nums, subnum, result, used):

        if len(subnum) == len(nums):
            if subnum not in result:
                result.append(subnum)
            return
        
        for i in range(len(nums)):
            if i not in used:
                used.add(i)
                self.permutation(nums, subnum.copy()+[nums[i]], result, used)
                used.remove(i)

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        results = []   
        used = set()

        self.permutation(nums, [], results, used)
        print(results)

        return results
