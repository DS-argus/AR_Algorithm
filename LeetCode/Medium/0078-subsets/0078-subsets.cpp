class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> elements;
        vector<vector<int>> result;
        vector<int>::iterator it = nums.begin();
        
        subsets(nums, elements, result, it); 
        
        return result;
    }
    
    void subsets(vector<int>& nums, vector<int> elements, vector<vector<int>>& result, vector<int>::iterator it) {
        if (it == nums.end()) {
            result.push_back(elements);
            return;
        }
        elements.push_back(*it);
        subsets(nums, elements, result, it+1);

        elements.pop_back();
        subsets(nums, elements, result, it+1);
    }
};