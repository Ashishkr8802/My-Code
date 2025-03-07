class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> map;

        for(int it : nums1) {
            map[it]++;
        }

        vector<int> ans;

        for(int i : nums2) {
            if(map.find(i) != map.end()) {
                ans.push_back(i);
                map[i]--;
                if(map[i] == 0) {
                    map.erase(i);
                }
            }
        }
        return ans;
    }
};