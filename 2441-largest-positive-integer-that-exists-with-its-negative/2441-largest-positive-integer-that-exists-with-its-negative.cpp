class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set;
        int maxi = -1;

        for(auto it : nums) {
            if(set.count(-it)) {
                maxi = max(maxi , abs(it));
            }
            set.insert(it);
        }

        return maxi;
    }
};