class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mapping;

        for(int it : arr) {
            mapping[it]++;
        }

        unordered_set<int> set;
        for(auto it: mapping) {
            set.insert(it.second);
        }

        return mapping.size() == set.size();
    }
};