class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        for(int i=0; i < m ; i++) {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin() , nums1.end());

        int k = n+m;
        float ans;

        if(k%2 != 0) {
            ans = nums1[k/2];
        }

        if(k%2 == 0) {
            ans = (nums1[k/2] + nums1[k/2 - 1]) / 2.0;
        }

        return ans;
    }
};