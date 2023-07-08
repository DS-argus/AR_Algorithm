class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // when size = 1;
        if (nums.size() == 1) return ((nums[0]==target)-1);

        // Find k by max value
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        int k;

        while(true){
            // size =2 혹은 이전 loop에서 mid가 min일 경우
            // mid가 min인 경우 end 바깥으로 나가 못찾는 걸 방지하기 위해 먼제 체크
            if(nums[end] > nums[(end+1)%nums.size()]){
                k = end + 1;
                break;
            }

            mid = (start + end) / 2;

            // mid가 max인 경우
            if(nums[mid]>nums[mid+1]){
                k = mid+1;
                break;
            }

            // mid가 max가 아닌 경우
            if (nums[mid]<nums[end]){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }

        // Find target value
        start = 0;
        end = nums.size()-1;
        int start_idx, mid_idx, end_idx;

        while(start != end+1){
            mid = (start + end) / 2;

            start_idx = (start + k) % nums.size();
            mid_idx = (mid + k) % nums.size();
            end_idx = (end + k) % nums.size();

            if(nums[mid_idx] < target){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }

        start_idx = (start + k) % nums.size();
        
        if (start < nums.size() && nums[start_idx]==target){
            return start_idx;
        }else{
            return -1;
        }
    }
};