class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        
        vector<int> sortedVec;
        int p1 = 0;
        int p2 = 0;
        
        while (sortedVec.size() != total){
            if(p1<nums1.size() && p2<nums2.size()){
                if (nums1[p1] > nums2[p2]){
                    sortedVec.push_back(nums2[p2]);
                    p2++;

                }else{
                    sortedVec.push_back(nums1[p1]);
                    p1++;
                }
            }else if(p1>=nums1.size()){
                sortedVec.push_back(nums2[p2]);
                p2++;
            }else{
                sortedVec.push_back(nums1[p1]);
                p1++;
            }
        }

        if (total%2 == 0){
            int mid = (total-1) / 2;
            float result = static_cast< float >((sortedVec[mid]+sortedVec[mid+1]))/2;
            return result;
        }else{
            int mid = (total-1) / 2;
            return sortedVec[mid];
        }
        
    }
};