class Solution(object):
    
    def permuteHelper(self, nums, subnums, results):
        if len(subnums) == len(nums):
            results.append(subnums)
            return
        
        for num in nums:
            if num not in subnums:
                self.permuteHelper(nums, subnums+[num], results)
                
    
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        
        self.permuteHelper(nums, [], results)
        
        return results
        