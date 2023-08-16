class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:
        
        result = []
        q = deque()
        q.append([])

        while q:
            cntList = q.popleft()

            if len(cntList) == len(nums):
                result.append(cntList)
            else:
                for num in nums:
                    if num not in cntList:
                        newList = cntList + [num]
                        q.append(newList)
        
        return result
