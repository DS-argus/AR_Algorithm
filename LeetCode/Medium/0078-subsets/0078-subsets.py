class Solution:

    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        q = deque()
        q.append([])

        while q:
            subSet = q.popleft()
            
            result.append(subSet)

            for num in nums:
                if subSet == [] or subSet[-1] < num:
                    nextSubset = subSet + [num]
                    q.append(nextSubset)
        
        return result