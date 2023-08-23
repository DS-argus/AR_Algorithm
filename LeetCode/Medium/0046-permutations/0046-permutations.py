class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.lens = len(nums)
        self.ids = [ele for ele in range(self.lens)]
        self.output = []
        self.nums = sorted(nums)
        
        self.permute_helper(self.ids, [])

        return self.output

    def permute_helper(self, id, temp) :
        if id == [] :
            self.output.append(temp)
            return

        else :
            for i in id :
                temps = temp.copy()
                # temps = deepcopy(temp)
                temps.append(self.nums[i])
                
                temp_id = id.copy()
                # temp_id = deepcopy(id)
                temp_id.remove(i)
                self.permute_helper(temp_id, temps)