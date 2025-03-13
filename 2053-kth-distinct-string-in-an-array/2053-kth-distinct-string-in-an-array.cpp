class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string , int> map;

        for(auto it : arr) {
            map[it]++;
        }

        int count = 0;

        for(auto it : arr) {
            if(map[it] == 1) {
                count++;
                if(count == k) {
                    return it;
                }
            }
        }

        return "";
    }
};