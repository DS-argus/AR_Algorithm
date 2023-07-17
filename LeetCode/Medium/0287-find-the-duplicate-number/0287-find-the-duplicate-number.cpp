class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int* arr = new int[nums.size()];

        for(int i = 0 ; i < nums.size() ; i++){
            if (arr[nums[i]-1] == -1){
                return nums[i];
            }else{
                arr[nums[i]-1] = -1;
            }
        }

        return -1;
    }
};