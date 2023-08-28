class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:

        
        res = []
        subset = []

        q = deque()
        q.append(subset)

        while q:

            subset = q.popleft()

            if len(subset) == len(nums):
                res.append(subset.copy())
            
            for num in nums:
                if num not in subset:
                    temp = subset.copy()
                    temp.append(num)
                    q.append(temp)
        return res




        # result = []

        # if (len(nums) == 1):
        #     return [nums[:]]

        # for i in range(len(nums)):
        #     n = nums.pop(0)
            
        #     perms = self.permute(nums)

        #     for perm in perms:
        #         perm.append(n)
        #     result.extend(perms)

        #     nums.append(n)
        
        # return result