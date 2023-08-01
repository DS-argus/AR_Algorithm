class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        set<vector<int>> resultSet;

        for(int i = 0; i<nums.size(); i++){
            
            int target = nums[i];
            
            vector<vector<int>> subresult = twoSum(nums, -target, i);

            if(subresult.size() != 0){
                for(auto i: subresult){
                    resultSet.insert(i);
                }
            }

        }

        // convert to vector
        vector<vector<int>> resultVec(resultSet.begin(), resultSet.end());

        return resultVec;

    }

private:
    vector<vector<int>> twoSum(vector<int>& numbers, int target, int idx) {
        int l = 0;
        int r = numbers.size()-1;
        if (l == idx) l = l+1;
        if (r == idx) r = r-1;

        vector<vector<int>> resultVec;

        while(l<r){

            if(numbers[l] + numbers[r] > target){
                r--;
                if (r == idx) r = r-1;
            }else if(numbers[l] + numbers[r] < target){
                l++;
                if (l == idx) l = l+1;
            }else{
                vector<int> subresult{-target, numbers[l], numbers[r]};
                sort(subresult.begin(), subresult.end());
                resultVec.push_back(subresult);                

                // l++;
                // if(l == idx) l = l+1 ;
                int temp = numbers[l];
                while(true){
                    l++;
                    if (l == idx) l = l+1;
                    if (l>=r || temp != numbers[l]) break;
                }
            }
        }

        return resultVec;
        
    }
};