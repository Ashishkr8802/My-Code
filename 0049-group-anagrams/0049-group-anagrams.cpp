class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mapping;

        for(int i=0 ; i < strs.size() ; i++) {
            string sorted = strs[i];
            sort(sorted.begin() , sorted.end());
            mapping[sorted].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto it : mapping) {
            ans.push_back(it.second);
        }

        return ans;
    }
};