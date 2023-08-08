class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, j = height.size()-1;
        int max_i = 0, max_j = 0;
        int sum = 0;
        while(i <= j){

            if(height[i] >= max_i){
                max_i = height[i];
                i++;       

            }else if(height[j] >= max_j){
                max_j = height[j];
                j--;

            }else if(max_i <= max_j && height[i] < max_i){
                sum += max_i - height[i];
                i++;
            }else{
                sum += max_j - height[j];
                j--;
            }
        }
        return sum;
    }
};