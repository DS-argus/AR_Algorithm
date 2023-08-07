class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;

        for(int i = 0; i<nums.size()-1; i++){
            
            if(i != 0 && nums[i-1] == nums[i]) continue;

            int l = i+1;
            int r = nums.size()-1;

            while(l<r){
                
                int L = nums[l];
                int R = nums[r];
                int threeSum = nums[i] + L + R;

                if (threeSum < 0){
                    while(l<r){
                        l++;
                        if(L != nums[l]) break;
                    }
                    
                }else if (threeSum > 0){
                    
                    while(l<r){
                        r--;
                        if(R != nums[r]) break;
                    }

                }else{
                    
                    vector<int> subresult{nums[i], nums[l], nums[r]};
                    result.push_back(subresult);
                    while(l<r){
                        l++;
                        if(L != nums[l]) break;
                    }

                }
            
            }

        }

        return result;
    }
};