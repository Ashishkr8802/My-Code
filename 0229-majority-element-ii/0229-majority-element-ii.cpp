class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mapping;

        for(int it : nums) {
            mapping[it]++;
        }

        vector<int> ans;

        for(auto i : mapping) {
            if(i.second > n/3) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};