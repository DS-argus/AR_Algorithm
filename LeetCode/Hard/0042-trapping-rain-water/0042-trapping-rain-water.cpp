class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size());
        vector<int> rmax(height.size());
        int output = 0;
        int trapped;

        for (int i = 1; i < height.size(); ++i) 
            lmax[i] = max(height[i-1], lmax[i-1]);
            
        for (int i = height.size()-2; i >= 0; --i) 
            rmax[i] = max(height[i+1], rmax[i+1]);
        
        

        for (int i = 0; i < height.size(); ++i) {
            trapped = min(lmax[i], rmax[i]);
            if (trapped >= height[i]) {
                output += trapped - height[i];
            }
        }
        return output;
    }
};