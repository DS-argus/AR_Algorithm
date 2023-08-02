class Solution {
public:
    int maxArea(vector<int>& height) {

        int l = 0;
        int r = height.size()-1;
        int maxArea = 0;
        int Area = 0;

        while(l<r){

            Area = (r-l) * min(height[l], height[r]);
            maxArea = max(maxArea, Area);

            if(height[l] > height[r]){
                r--;
            }else if(height[l] < height[r]){
                l++;
            }else{
                height[l+1]>=height[r-1]? l++:r--;
            }
        }

        return maxArea;        

    }
};