class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> ans;
        int n2 = nums2.size();
        for(int i:nums1) {
            s.insert(i);
        }

        for(int i=0 ; i<n2 ; i++) {
            if(s.find(nums2[i]) != s.end()) {
                ans.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }

        return ans;

    }
};