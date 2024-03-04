class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:

        results = []
        subset = []
        q = [subset]

        while q:

            subset = q.pop(0)

            if len(subset) == len(nums):
                results.append(subset.copy())
            
            for num in nums:
                if num not in subset:
                    q.append(subset.copy()+[num])

        return results




#      def permuteHelper(self, nums, subnums, results):
#         if len(subnums) == len(nums):
#             results.append(subnums)
#             return
        
#         for num in nums:
#             if num not in subnums:
#                 self.permuteHelper(nums, subnums+[num], results)
                
    
#     def permute(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[List[int]]
#         """
#         results = []
        
#         self.permuteHelper(nums, [], results)
        
#         return results