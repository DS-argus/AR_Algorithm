class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start != end + 1){
            mid = (start + end) / 2;

            if(nums[mid] >= target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

        if(start < nums.size() && nums[start]==target){
            return start;
        }else{
            return -1;
        }
        
    }
};