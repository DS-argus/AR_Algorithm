class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:

        nums.sort()
        res = []
        q = deque()
        q.append([])

        while q:
            subset = q.popleft()

            if subset not in res:
                res.append(subset.copy())

            for num in nums:
                if subset == [] or num > subset[-1]:
                    temp = subset.copy()
                    temp.append(num)
                    q.append(temp)
        
        return res

            
            
            







        # res = []

        # subset = []

        # def dfs(i):
        #     if i >= len(nums):
        #         res.append(subset.copy())
        #         return
        #     # decision to include nums[i]
        #     subset.append(nums[i])
        #     dfs(i + 1)
        #     # decision NOT to include nums[i]
        #     subset.pop()
        #     dfs(i + 1)

        # dfs(0)
        # return res