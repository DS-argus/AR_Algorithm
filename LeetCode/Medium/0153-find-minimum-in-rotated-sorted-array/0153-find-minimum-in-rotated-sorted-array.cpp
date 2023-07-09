class Solution {
public:
    int findMin(vector<int>& nums) {
        
         // when size = 1;
        if (nums.size() == 1) return nums[0];

        // Find k by max value
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        int k;

        while(true){
            // size =2 혹은 이전 loop에서 mid가 min일 경우
            // mid가 min인 경우 end 바깥으로 나가 못찾는 걸 방지하기 위해 먼제 체크
            if(nums[end] > nums[(end+1)%nums.size()]){
                return nums[(end+1)%nums.size()];
            }

            mid = (start + end) / 2;

            // mid가 max인 경우
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }

            // mid가 max가 아닌 경우
            if (nums[mid]<nums[end]){
                end = mid -1;
            }else{
                start = mid + 1;
            }
        }
        
    }
};