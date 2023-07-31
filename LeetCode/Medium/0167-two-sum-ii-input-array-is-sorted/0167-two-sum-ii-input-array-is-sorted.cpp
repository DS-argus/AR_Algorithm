class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> result;

        while(numbers[l] + numbers[r] != target){
            numbers[l] + numbers[r] > target? r-- : l++;
        }

        result.push_back(l+1);
        result.push_back(r+1);
        return result;
    }
};