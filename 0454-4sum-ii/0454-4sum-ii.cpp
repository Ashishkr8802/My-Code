class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int , int> map;
        int ans = 0;

        for(int i : nums1) {
            for(int j : nums2) {
                map[i+j]++;
            }
        }

        for(int a : nums3) {
            for(int b : nums4) {
                ans += map[-(a+b)]++;
            }
        }

        return ans;
    }
};