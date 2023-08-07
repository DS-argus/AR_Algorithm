class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        set<vector<int>> s;

        int j, k;
        int len = nums.size()-1;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++){
            j = i+1;
            k = nums.size()-1;
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum < -nums[i]) j++;
                else if(sum > -nums[i]) k--;
                else{
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }
        output.assign(s.begin(),s.end());
        return output;
    }
};